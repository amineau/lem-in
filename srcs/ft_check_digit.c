#include "lem-in.h"

int ft_check_digit(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i++]))
            return (0);
    }
    return (1);
}