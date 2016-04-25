#include "lem-in.h"

t_room  *ft_listcreate_room(char **tab, int pos)
{
    t_room  *room;
    
    room = (t_room*)ft_memalloc(sizeof(t_room));
    room->name = tab[0];
    room->x = ft_atoi(tab[1]);
    room->y = ft_atoi(tab[2]);
    room->pos = pos;
    room->next = NULL;
    return (room);
}

void    ft_listadd_room(t_room **begin, char ** tab, int pos)
{
    t_room   *tmp;
    
    if ((tmp = *begin))
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ft_listcreate_room(tab, pos);
    }
    else
        *begin = ft_listcreate_room(tab, pos);
}