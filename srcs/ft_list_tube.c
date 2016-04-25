#include "lem-in.h"

t_tube  *ft_listcreate_tube(t_room *room)
{
    t_tube  *tube;
    
    tube = (t_tube*)ft_memalloc(sizeof(t_tube));
    tube->room = room;
    tube->next = NULL;
    return (tube);
}

void    ft_listadd_tube(t_room *room, t_room *add)
{
    t_tube   *tmp;
    
    if ((tmp = room->tube))
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ft_listcreate_tube(add);
    }
    else
        room->tube = ft_listcreate_tube(add);
}