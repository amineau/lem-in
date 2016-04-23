#include "lem-in.h"

void    ft_error(t_global *glob)
{
    ft_clear(glob);
    ft_printf("ERROR\n");
    exit(1);
}