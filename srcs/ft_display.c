#include "lem-in.h"

void	ft_display(t_ant **ant, char **list)
{
	t_ant   *tmp;
    
    tmp = *ant;
    while (tmp)
    {
     	if (tmp->move)
     	{
	        ft_printf("L%d-%s", tmp->id, list[tmp->room]);
	        if (tmp->next)
	            ft_putchar(' ');
     	}
        tmp = tmp->next;
    }
    ft_putchar('\n');
}