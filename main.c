#include "header/libft.h"
#include "header/libftprintf.h"

#include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_printf("moi '%x', '%X'\n", 100000, 100000));
// 	printf("%d\n", printf("fc '%x', '%X'\n", 100000, 100000));
// 	return (0);
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "header/libftprintf.h"

typedef struct s_capture
{
    int     saved;
    FILE    *file;
}   t_capture;

static int total = 0;
static int failed = 0;

static int begin_capture(t_capture *cap)
{
    if (fflush(stdout) != 0)
        return (-1);
    cap->saved = dup(STDOUT_FILENO);
    if (cap->saved < 0)
        return (-1);
    cap->file = tmpfile();
    if (!cap->file)
    {
        close(cap->saved);
        return (-1);
    }
    if (dup2(fileno(cap->file), STDOUT_FILENO) < 0)
    {
        fclose(cap->file);
        close(cap->saved);
        return (-1);
    }
    return (0);
}

static unsigned char *end_capture(t_capture *cap, size_t *len)
{
    long            n;
    unsigned char   *buf;

    if (fflush(stdout) != 0)
        exit(2);
    if (dup2(cap->saved, STDOUT_FILENO) < 0)
        exit(2);
    close(cap->saved);
    if (fseek(cap->file, 0, SEEK_END) != 0)
        exit(2);
    n = ftell(cap->file);
    if (n < 0 || fseek(cap->file, 0, SEEK_SET) != 0)
        exit(2);
    buf = malloc((size_t)n + 1);
    if (!buf)
        exit(2);
    *len = fread(buf, 1, (size_t)n, cap->file);
    fclose(cap->file);
    if (*len != (size_t)n)
        exit(2);
    return (buf);
}

static void escaped(const unsigned char *s, size_t n)
{
    size_t      i;
    const char  *hex = "0123456789abcdef";

    i = 0;
    while (i < n)
    {
        if (s[i] >= 32 && s[i] <= 126
            && s[i] != '\\' && s[i] != '\'')
            fputc(s[i], stderr);
        else
        {
            fputc('\\', stderr);
            fputc('x', stderr);
            fputc(hex[s[i] >> 4], stderr);
            fputc(hex[s[i] & 15], stderr);
        }
        i++;
    }
}

static void compare(const char *name, int expected, int actual,
    const unsigned char *a, size_t an,
    const unsigned char *b, size_t bn)
{
    total++;
    if (expected == actual && an == bn
        && memcmp(a, b, an) == 0)
        return;
    failed++;
    fprintf(stderr, "[FAIL] %s\n", name);
    fprintf(stderr, "  printf    ret=%d bytes=%zu: '",
        expected, an);
    escaped(a, an);
    fprintf(stderr, "'\n");
    fprintf(stderr, "  ft_printf ret=%d bytes=%zu: '",
        actual, bn);
    escaped(b, bn);
    fprintf(stderr, "'\n");
}

#define TEST(name, fmt, ...) do {                      \
    t_capture _cap;                                   \
    unsigned char *_a, *_b;                           \
    size_t _an, _bn;                                  \
    int _ra, _rb;                                     \
    if (begin_capture(&_cap) < 0) exit(2);            \
    _ra = printf(fmt, ##__VA_ARGS__);                 \
    _a = end_capture(&_cap, &_an);                    \
    if (begin_capture(&_cap) < 0) exit(2);            \
    _rb = ft_printf(fmt, ##__VA_ARGS__);              \
    _b = end_capture(&_cap, &_bn);                    \
    compare(name, _ra, _rb, _a, _an, _b, _bn);         \
    free(_a);                                         \
    free(_b);                                         \
} while (0)

#define TEST_EMPTY() do {                             \
    t_capture _cap;                                   \
    unsigned char *_a, *_b;                           \
    size_t _an, _bn;                                  \
    int _ra, _rb;                                     \
    if (begin_capture(&_cap) < 0) exit(2);            \
    _ra = printf("%s", "");                           \
    _a = end_capture(&_cap, &_an);                    \
    if (begin_capture(&_cap) < 0) exit(2);            \
    _rb = ft_printf("");                              \
    _b = end_capture(&_cap, &_bn);                    \
    compare("empty format", _ra, _rb,                  \
        _a, _an, _b, _bn);                            \
    free(_a);                                         \
    free(_b);                                         \
} while (0)

int main(void)
{
    int i;
    int number = 42;
    char mutable[] = "modifiable";

    const int values[] = {
        0, 1, -1, 2, -2, 9, -9,
        10, -10, 99, -99, 100, -100,
        999, -999, 1000, -1000,
        INT_MIN, INT_MAX
    };

    const unsigned int uvalues[] = {
        0U, 1U, 9U, 10U, 15U, 16U, 17U,
        255U, 256U, 4095U, 4096U,
        65535U, 65536U, UINT_MAX
    };

    /* ====================== */
    /* FORMATS ET POURCENTAGES */
    /* ====================== */

    TEST_EMPTY();
    TEST("literal", "hello world");
    TEST("newline", "hello\nworld");
    TEST("tab", "\t");
    TEST("percent", "%%");
    TEST("many percent", "%%%%%%%%%%%%");
    TEST("percent around text", "a%%b%%c");
    TEST("percent mixed", "abc%%def%%ghi");
    TEST("text and percent", "hello %% world");

    /* ====================== */
    /* CARACTERES              */
    /* ====================== */

    TEST("char normal", "%c", 'A');
    TEST("char null", "%c", 0);
    TEST("char newline", "%c", '\n');
    TEST("char tab", "%c", '\t');
    TEST("char 127", "%c", 127);
    TEST("char 255", "%c", 255);
    TEST("char negative", "%c", -1);
    TEST("multiple chars", "%c%c%c%c", 0, 'A', 0, 'Z');
    TEST("chars mixed", "a%cb%cc", 'X', 'Y');

    /* ====================== */
    /* CHAINES                 */
    /* ====================== */

    TEST("empty string", "%s", "");
    TEST("normal string", "%s", "hello world");
    TEST("special string", "%s", "x\ny\tz");
    TEST("mutable string", "%s", mutable);
    TEST("multiple strings", "[%s]-%s", "abc", "def");
    TEST("long string", "%s",
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789");
    TEST("string surrounded", "START[%s]END", "test");

    /* ====================== */
    /* POINTEURS               */
    /* ====================== */

    TEST("pointer local", "%p", (void *)&number);
    TEST("pointer char", "%p", (void *)mutable);
    TEST("pointer null", "%p", (void *)NULL);
    TEST("pointer repeated", "%p %p",
        (void *)&number, (void *)&number);
    TEST("pointer with text", "addr=[%p]", (void *)&i);

    /* ====================== */
    /* CONVERSIONS MELANGEES   */
    /* ====================== */

    TEST("mixed",
        "A:%d B:%i C:%u D:%x E:%X F:%c G:%s P:%p %%",
        -42, 17, 42U, 255U, 255U,
        'K', "done", (void *)&number);

    TEST("mixed integers", "%d|%u|%x|%X",
        -1, UINT_MAX, 255U, 255U);

    TEST("mixed null chars", "%c%s%c%d",
        0, "abc", 0, 123);

    TEST("repeated strings", "%s%s%s",
        "a", "b", "c");

    /* ====================== */
    /* 256 CARACTERES          */
    /* ====================== */

    i = 0;
    while (i < 256)
    {
        TEST("all 256 chars", "%c", i);
        i++;
    }

    /* ====================== */
    /* ENTIERS SIGNES          */
    /* ====================== */

    i = 0;
    while (i < (int)(sizeof(values) / sizeof(values[0])))
    {
        TEST("decimal d", "%d", values[i]);
        TEST("decimal i", "%i", values[i]);
        TEST("decimal repeated", "%d|%i|%d",
            values[i], values[i], values[i]);
        i++;
    }

    /* ====================== */
    /* NON SIGNES ET HEXA      */
    /* ====================== */

    i = 0;
    while (i < (int)(sizeof(uvalues) / sizeof(uvalues[0])))
    {
        TEST("unsigned", "%u", uvalues[i]);
        TEST("lower hex", "%x", uvalues[i]);
        TEST("upper hex", "%X", uvalues[i]);
        TEST("unsigned mixed", "%u-%x-%X",
            uvalues[i], uvalues[i], uvalues[i]);
        i++;
    }

    /* ====================== */
    /* STRESS DECIMAL          */
    /* ====================== */

    i = -1000;
    while (i <= 1000)
    {
        TEST("decimal sweep", "%d", i);
        TEST("integer sweep", "%i", i);
        i++;
    }

    /* ====================== */
    /* STRESS HEXADECIMAL      */
    /* ====================== */

    i = 0;
    while (i < 1000)
    {
        TEST("hex sweep", "%x %X",
            (unsigned int)i, (unsigned int)i);
        TEST("unsigned sweep", "%u", (unsigned int)i);
        i++;
    }

    /* ====================== */
    /* RESULTAT FINAL          */
    /* ====================== */

    fprintf(stderr,
        "\n================================\n"
        "RESULT: %d/%d passed\n"
        "FAILED: %d\n"
        "================================\n",
        total - failed, total, failed);

    return (failed != 0);
}

