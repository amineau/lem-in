#include "lem-in.h"

int *ft_tabcpy(int *tab, int length)
{
    int i;
    int *new;
    
    i = 0;
    new = (int*)ft_memalloc(sizeof(int) * length);
    while (i < length)
    {
        new[i] = tab[i];
        i++;
    }
    return (new);
}

void    ft_set_matrice(int **matrice, int x, int y, int val)
{
    matrice[y][x] = val;
	matrice[x][y] = val;
}

int	ft_path(t_matrice *m, int id, int cnt)
{
	int	x;
 
	if (id != 1)
	{
		x = 0;
		while (x < m->length)
		{
			if (m->matrice[id][x])
			{
			    ft_set_matrice(m->matrice, x, id, 0);
				m->tmp[cnt] = x;
				cnt = ft_path(m, x, ++cnt);
				m->tmp[cnt - 1] = 0;
				ft_set_matrice(m->matrice, x, id, 1);
			}
			x++;
		}
	}
	if (id == 1 && cnt < m->min)
	{
	    m->min = cnt;
        ft_memdel((void**)&(m->path_min));
	    m->path_min = ft_tabcpy(m->tmp, m->length);
        cnt = 0;
	}
	return (cnt);
}

void    ft_clean_matrice(int **matrice, int length, int id)
{
    int i;
    
    i = 0;
    while (i < length)
    {
        matrice[id][i] = 0;
        matrice[i++][id] = 0;
    }
} 

void    ft_reset_matrice(t_matrice *m, t_path **p)
{
    t_path  *tmp;
    int     i;
    
    tmp = *p;
    m->min = m->length + 1;
    ft_clear_tabint(m->path_min, m->length);
    ft_clear_tabint(m->tmp, m->length);
    while (tmp)
    {
        i = 0;
        if (tmp->path[0] == 1)
            ft_set_matrice(m->matrice, 0, 1, 0);
        while (tmp->path[i] != 1)
            ft_clean_matrice(m->matrice, m->length, tmp->path[i++]);
        tmp = tmp->next;
    }
}

t_path  **ft_algo_multi(t_matrice *m, int max_path)
{
    t_path  **p;
    
    p = (t_path**)ft_memalloc(sizeof(t_path*));
    ft_putendl("coucou");
    ft_path(m, 0, 0);
    ft_putendl("coucou");
    if (m->min > m->length)
        ft_error();
    *p = ft_listcreate_path(m->path_min, m->min);
     while (--max_path > 0)
     {
         ft_reset_matrice(m, p);
         ft_path(m, 0, 0);
         if (m->min <= m->length)
            ft_listadd_path(p, m->path_min, m->min);
     }
     ft_clear_matrice(m);
     return (p);
}