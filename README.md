*This project has been created as part of the 42 curriculum by mjardin.*

# Description

The goal of this project is to remake a part of the function "printf", this function print the string you write in first param and can take some variables as params and can print it easily in your final string with : %d for int, %s for strings, %c for char...

>Exemple : 
>
>char	*s = "ca va ?";
>
>printf("Bonjour %s\n", s);
>
>-> Bonjour ca va ?

# Instructions

To compile the libftprintf you can write "Make" in the console. To use it you have to get libftprintf.a, ft_printf.h and a main.c in your file and include "ft_printf.h" in the files that use the functions of the libftprintf. Compile the libftprintf.a with your main.c and your other files. Exemple : cc -Wall -Werror -Wextra main.c libftprintf.a

And now you can use your ft_printf function in your files.

# Resources

I used man 3 printf to understand some types,
this youtube video: https://www.youtube.com/watch?v=LB2vPYwJnfw.
I also used 2 testers to see if my function is working and I used AI to understand somes way to write something i want, like i didnt used Index in my function but some times i was blocked to send correctly my string in functions or to increment the value of a pointer in others functions but it didnt code anything in my project.


### Explanation of the choosen algorithm

I choose to read the sent string and when I read a '%' i look if the next index is part of the types else i return -1; if it is i enter in a function that run function for each types corresponding. As the function should return an int of the total lenght of the written string everytime i write characters i increment the counter and at the end i return it.