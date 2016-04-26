#include "lem-in.h"

int	ft_path(int **matrice, int length, int id, int cnt)
{
	int	x;
/******** Test Matrice *********/
	ft_printf("****************************Matrice*****************************\n");
    int i = 0;
    int j;
    ft_printf("   ");
    while (i < length)
        ft_printf("%2d ", i++);
    ft_printf("\n");
    i = 0;
    while (i < length)
    {
        j = 0;
        ft_printf("%2d ", i);
        while (j < length)
            ft_printf("%2d ", matrice[i][j++]);
        i++;
        ft_printf("\n");
    }
 /********************************/
	if (id != 1)
	{
		x = 0;
		ft_printf("id = %d\n", id);
		while (x < length)
		{
			if (matrice[id][x])
			{
				matrice[id][x] = 0;
				matrice[x][id] = 0;
				cnt = ft_path(matrice, length, x, cnt++);
			}
			x++;
		}
	}
	ft_printf("cnt = %d\n", cnt);
	return (cnt);
}