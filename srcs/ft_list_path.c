#include "lem-in.h"

t_path  *ft_listcreate_path(t_room *room)
{
    t_path  *path;
    
    path = (t_path*)ft_memalloc(sizeof(t_path));
    path->room = room;
    path->next = NULL;
    return (path);
}