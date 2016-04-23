#include "lem-in.h"

void    ft_clear(t_global *glob)
{
    ft_memdel((void**)&glob);
}