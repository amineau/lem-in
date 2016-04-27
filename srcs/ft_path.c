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

int	ft_path(t_matrice *m, int id, int cnt)
{
	int	x;
	
	
/******** Test Matrice *********/
	ft_printf("****************************Matrice*****************************\n");
    int i = 0;
    int j;
    ft_printf("   ");
    while (i < m->length)
        ft_printf("%2d ", i++);
    ft_printf("\n");
    i = 0;
    while (i < m->length)
    {
        j = 0;
        ft_printf("%2d ", i);
        while (j < m->length)
        {
            if (m->matrice[i][j])
            	ft_printf("\033[32m%2d \033[0m", m->matrice[i][j++]);
            else
                ft_printf("%2d ", m->matrice[i][j++]);
        }
        i++;
        ft_printf("\n");
    }
 /********************************/
 
 
	if (id != 1)
	{
		x = 0;
		ft_printf("id = %d\n", id);
		while (x < m->length)
		{
			if (m->matrice[id][x])
			{
				m->matrice[id][x] = 0;
				m->matrice[x][id] = 0;
				m->tmp[cnt] = x;
				cnt = ft_path(m, x, ++cnt);
				m->tmp[cnt - 1] = 0;
				m->matrice[id][x] = 1;
				m->matrice[x][id] = 1;
			}
			x++;
		}
	}

	if (id == 1 && cnt < m->min)
	{
	    ft_printf("cnt = %d || m->min = %d || path = ", cnt, m->min);
	    m->min = cnt;
	    m->path_min = ft_tabcpy(m->tmp, m->length);
	    	i = 0;
	    while (i < m->min)
	        ft_printf("%d ", m->path_min[i++]);
	}

	cnt = 0;
	return (cnt);
}