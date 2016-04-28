#include "lem-in.h"

int         ft_reading_ant(t_global *glob, char *ptr)
{
    int     i;
    int     nb;
    
    if (!ft_check_digit(ptr))
        ft_error();
    glob->ant = (t_ant**)ft_memalloc(sizeof(t_ant*));
    if ((nb = ft_atoi(ptr)) == 0)
        ft_error();
    i = 1;
    while (i <= nb)
        ft_listadd_ant(glob->ant, i++);
    return (2);
}

int         ft_reading_anthill(t_global *glob, char *ptr, int status_read)
{
    char    **tab;
    
    if (!ft_strcmp(ptr, ""))
        return (0);
    tab = ft_strsplit(ptr, ' '); //tab à free ***************************************
    if (ptr[0] == '#' && status_read != 3)
    {
        if (ft_strcmp(ptr, "##start") && ft_strcmp(ptr, "##end"))
            return (2);
    }
    else if (!glob->tunnel && tab[1])
    {
        if (!ft_check_digit(tab[1]) || !tab[2] || !ft_check_digit(tab[2]) || tab[3])
            ft_error();
    }
    else if (status_read == 3 || ptr[0] == 'L')
        ft_error();
    else
    {
        if (tab[1] || !ft_strchr(ptr, '-'))
            ft_error();
        glob->tunnel = 1;
    }
    glob->hill = ft_straddc(ft_strcln1join(glob->hill, ptr), '\n');
    if (!ft_strcmp(ptr, "##start") || !ft_strcmp(ptr, "##end"))
        return (3);
    return (2);
}

t_global    *ft_recovery(void)
{
    char        *ptr;
    int         status_read;
    t_global    *glob;
    

    glob = (t_global*)ft_memalloc(sizeof(t_global));
    glob->hill = (char*)ft_memalloc(1);
    glob->tunnel = 0;
    status_read = 1;
    while (get_next_line(0, &ptr) == 1 && status_read)
	{
	    if (status_read == 1)
	        status_read = ft_reading_ant(glob, ptr);
	    else
	        status_read = ft_reading_anthill(glob, ptr, status_read);
		ft_strdel(&ptr);
	}
    ft_putendl(glob->hill);
	return (glob);
}