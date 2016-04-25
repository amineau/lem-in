#include "lem-in.h"

void    ft_starting_room(t_global *glob) //(t_room *start, t_ant **ant)
{
    t_ant   *ant;
    t_room  *start;
    ant = *(glob->ant);
    start = *(glob->room);
    while (start->pos != 0)
        start = start->next;
    while (ant)
    {
        ant->room = start;
        ant = ant->next;
    }
}

t_ant   *ft_listcreate_ant(int id)
{
    t_ant   *ant;
    
    ant = (t_ant*)ft_memalloc(sizeof(t_ant));
    ant->id = id;
    ant->next = NULL;
    return (ant);
}

void    ft_listadd_ant(t_ant **begin, int id)
{
    t_ant   *tmp;
    
    if ((tmp = *begin))
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ft_listcreate_ant(id);
    }
    else
        *begin = ft_listcreate_ant(id);
}