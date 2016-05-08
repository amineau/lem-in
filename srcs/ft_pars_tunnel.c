/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_tunnel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:21:05 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 16:30:35 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_cmp_name(char *tun, char **room)
{
	int	i;

	i = 0;
	while (room[i])
	{
		if (!ft_strcmp(tun, room[i++]))
			return (1);
	}
	return (0);
}

static char	**ft_chtun(char **tab, int id, t_global *glob)
{
	char	**tun;
	char	*str;
	int		i;

	if (!(tun = ft_strsplit(tab[id], '-')))
		ft_error();
	if (tun[0][0] != '#' || !ft_strcmp(tun[0], "##start")
			|| !ft_strcmp(tun[0], "##end"))
	{
		if (!tun[1] || tun[2] || !ft_strcmp(tun[0], tun[1])
				|| !ft_cmp_name(tun[0], glob->room)
				|| !ft_cmp_name(tun[1], glob->room))
		{
			i = 0;
			str = glob->hill;
			while (i++ < id)
				str = ft_strchr(&str[1], '\n');
			str[1] = '\0';
			ft_clear_tabchar(tun);
			return (NULL);
		}
	}
	return (tun);
}

char		***ft_pars_tunnel(t_global *glob)
{
	int		i;
	int		lth;
	char	**tab;
	char	***tunnel;

	i = 0;
	if (!(tab = ft_strsplit(glob->hill, '\n')))
		ft_error();
	while (tab[i] && (ft_strchr(tab[i], ' ') || tab[i][0] == '#'))
		i++;
	lth = 0;
	while (tab[i + lth])
		lth++;
	if (!(tunnel = (char***)ft_memalloc(sizeof(char**) * (lth + 1))))
		ft_error();
	lth = -1;
	while (tab[i + ++lth])
	{
		if (!(tunnel[lth] = ft_chtun(tab, i + lth, glob)))
			break ;
	}
	tunnel[lth] = NULL;
	ft_clear_tabchar(tab);
	return (tunnel);
}

static int	ft_find_idroom(char **room, char *name)
{
	int	i;

	i = 0;
	while (room[i])
	{
		if (!ft_strcmp(room[i++], name))
			return (i - 1);
	}
	return (-1);
}

int			**ft_stock_tunnel(t_global *glob, char ***tunnel)
{
	int	i;
	int	**matrice;
	int	x;
	int	y;

	if (!(matrice = (int**)ft_memalloc(sizeof(int*) * glob->length)))
		ft_error();
	i = 0;
	while (i < glob->length)
	{
		if (!(matrice[i++] = (int*)ft_memalloc(sizeof(int) * glob->length)))
			ft_error();
	}
	i = -1;
	while (tunnel[++i])
	{
		if (tunnel[i][0][0] != '#')
		{
			x = ft_find_idroom(glob->room, tunnel[i][0]);
			y = ft_find_idroom(glob->room, tunnel[i][1]);
			matrice[x][y] = 1;
			matrice[y][x] = 1;
		}
	}
	return (matrice);
}
