#include "lem-in.h"

t_path   *ft_listcreate_path(int *path, int size)
{
    t_path   *p;
    
    p = (t_path*)ft_memalloc(sizeof(t_path));
    p->size = size;
    p->path = ft_tabcpy(path, size);
    p->next = NULL;
    return (p);
}

void    ft_listadd_path(t_path **begin, int *path, int size)
{
    t_path   *tmp;
    
    tmp = *begin;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = ft_listcreate_path(path, size);
}