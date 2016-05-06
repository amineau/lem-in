/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recovery.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:14:42 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 16:29:38 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_reading_ant(t_global *glob, char *ptr)
{
	int	i;
	int	nb;

	if (ptr[0] == '#' && ft_strcmp("##start", ptr) && ft_strcmp("##end", ptr))
	{
		glob->com = ft_straddc(ft_strcln1join(glob->com, ptr), '\n');
		return (1);
	}
	if (!ft_check_digit(ptr))
		ft_error();
	glob->ant = (t_ant**)ft_memalloc(sizeof(t_ant*));
	if ((nb = ft_atoi(ptr)) == 0)
		ft_error();
	i = 1;
	while (i <= nb)
		ft_listadd_ant(glob->ant, i++);
	return (2);
}

int			ft_reading_anthill(t_global *glob, char *ptr)
{
	char	**tab;

	if (!ft_strcmp(ptr, ""))
		return (0);
	if (ptr[0] == '#')
		;
	else if (!glob->tunnel && ft_strchr(ptr, ' '))
	{
		tab = ft_strsplit(ptr, ' ');
		if (!tab[1] || !ft_check_integer(tab[1]) || !tab[2]
			|| !ft_check_integer(tab[2]) || tab[3] || ptr[0] == 'L')
			ft_error();
		ft_clear_tabchar(tab);
	}
	else
		glob->tunnel = 1;
	glob->hill = ft_straddc(ft_strcln1join(glob->hill, ptr), '\n');
	return (2);
}

t_global	*ft_recovery(void)
{
	char		*ptr;
	int			status_read;
	t_global	*glob;

	glob = (t_global*)ft_memalloc(sizeof(t_global));
	glob->hill = ft_strdup("");
	glob->com = ft_strdup("");
	glob->tunnel = 0;
	status_read = 1;
	while (get_next_line(0, &ptr) == 1 && status_read)
	{
		if (status_read == 1)
			status_read = ft_reading_ant(glob, ptr);
		else
			status_read = ft_reading_anthill(glob, ptr);
		ft_strdel(&ptr);
	}
	ft_strdel(&ptr);
	return (glob);
}
