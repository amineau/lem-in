#include "lem-in.h"

void    ft_simple_move(t_ant *ant, int room, int *tab)
{
    tab[ant->room] = 0;
    ant->room = room;
    if (room != 1)
        tab[room] = 1;
}

int     ft_check_disp_room(t_path *p, t_ant *ant, int *tab)
{
    int i;
    while (p)
    {
            i = 0;
            while (i < p->size)
            {
                if (ant->room == p->path[i])
                {
                    if (tab[p->path[i + 1]] == 0)
                        ft_simple_move(ant, p->path[i + 1], tab);
                    else
                        return (0);
                    return (1);
                }
                i++;
            }
        p = p->next;
    }
    return (0);
}

int     ft_check_start_room(t_path *p, t_ant *ant, int *tab)
{
    while (p)
    {
        if (tab[p->path[0]] == 0)
        {
            ft_simple_move(ant, p->path[0], tab);
            return (1);
        }          
        p = p->next;
    }
    return (0);
}

int     ft_check_finish(t_ant **ant)
{
    t_ant   *tmp;
    
    tmp = *ant;
    while (tmp)
    {
        if (tmp->room != 1)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

char    **ft_listing_room(t_room *room, int length)
{
    char    **list;
    
    list = (char**)ft_memalloc(sizeof(char*) * length);
    while (room)
    {
        list[room->pos] = room->name;
        room = room->next;
    }
    return (list);
}

void    ft_moving_ant(t_global *glob, t_path **p)
{
    int     tab[glob->length];
    t_ant   *ant;
    t_path  *tmp;
    
    ft_clear_tab(tab, glob->length);
    while (!ft_check_finish(glob->ant))
    {
        ant = *(glob->ant);
        while (ant)
        {
            tmp = *p;
            if (ant->room == 0)
                ant->move = ft_check_start_room(tmp, ant, tab);
            else if (ant->room != 1)
                ant->move = ft_check_disp_room(tmp, ant, tab);
            else
                ant->move = 0;
            ant = ant->next;
        }
        ft_display(glob->ant, ft_listing_room(*(glob->room), glob->length));
    }
}