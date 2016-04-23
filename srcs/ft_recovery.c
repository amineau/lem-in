#include "lem-in.h"

int         ft_reading_ant(t_global *glob, char *ptr)
{
    int     i;
    int     nb;
    
    if (!ft_check_digit(ptr))
        ft_error(glob);
    glob->ant = (t_ant**)ft_memalloc(sizeof(t_ant*));
    if ((nb = ft_atoi(ptr)) == 0)
        ft_error(glob);
    i = 1;
    while (i <= nb)
        ft_listadd_ant(glob->ant, i++);
    return (2);
}

int         ft_reading_anthill(t_global *glob)
{
    
}

t_global    *ft_recovery(void)
{
    char        *ptr;
    int         status_read;
    t_global    *glob;
    
    glob = (t_global*)ft_memalloc(sizeof(t_global));
    glob->hill = (char*)ft_memalloc(1);
    status_read = 1;
    while (get_next_line(0, &ptr) == 1 && status_read)
	{
	    if (status_read == 1)
	        status_read = ft_reading_ant(glob, ptr);
	    else
	        status_read = ft_reading_anthill(glob, ptr);
		ft_strdel(&ptr);
	}
	
	return (glob);
}