#include "lem-in.h"

void	ft_display(t_ant **ant)
{
	t_ant   *tmp;
    tmp = *ant;
    while (tmp)
    {
    	if (tmp->move && tmp->room != 1)
    	{
	        ft_printf("L%d-%d", tmp->id, tmp->room);
	        if (tmp->next)
	            ft_putchar(' ');
    	}
        tmp = tmp->next;
    }
    ft_putchar('\n');
}