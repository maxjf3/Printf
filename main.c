#include "libft.h"
#include "printf.h"

#include <stdio.h>

int	main(void)
{
	printf("Moi %d\n", ft_printf("Moi: %s %c %d\n", "cacalol", 'y', 1234567890));
	printf("Elle %d\n", printf("Vrai %s %c %d\n", "cacalol", 'y', 1234567890));
	return (0);
}
