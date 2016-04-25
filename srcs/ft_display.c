#include "lem-in.h"

void	ft_display(t_global *glob)
{
	t_ant   *tmp;
    tmp = *(glob->ant);
    while (tmp)
    {
    	if (tmp->move)
    	{
	        ft_printf("L%d-%s", tmp->id, tmp->room->name);
	        if (tmp->next)
	            ft_putchar(' ');
	        else
	            ft_putchar('\n');
    	}
        tmp = tmp->next;
    }
}