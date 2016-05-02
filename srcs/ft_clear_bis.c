#include "lem-in.h"

void	ft_clear_dbltab(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_clear_tabchar(tab[i++]);
	free(tab);
}

void	ft_clear_glob(t_global *glob)
{
	ft_clear_ant(glob->ant);
	ft_clear_tabchar(glob->room);
	ft_strdel(&(glob->hill));
	free(glob);
}