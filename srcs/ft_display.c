#include "lem-in.h"

void	ft_display(t_ant **ant, char **list)
{
	t_ant   *tmp;
    int     bol;
    
    bol = 0;
    tmp = *ant;
    while (tmp)
    {
     	if (tmp->move)
     	{
            if (bol == 1)
                ft_putchar(' ');
            bol = 1;
	        ft_printf("L%d-%s", tmp->id, list[tmp->room]);
     	}
        tmp = tmp->next;
    }
    ft_putchar('\n');
}