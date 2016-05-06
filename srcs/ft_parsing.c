/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:16:18 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 16:17:07 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_cnt_room(char ***room)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (room[i])
	{
		if (room[i][0][0] == '#')
		{
			if (!ft_strcmp("##start", room[i][0])
				|| !ft_strcmp("##end", room[i][0]))
				i++;
			if (!room[i])
				ft_error();
			cnt++;
		}
		else
			cnt++;
		i++;
	}
	return (cnt);
}

void	ft_check_double(char **room)
{
	int	i;
	int	j;

	i = 0;
	while (room[i])
	{
		if (room[i][0] != '#')
		{
			if (ft_strchr(room[i], '-'))
				ft_error();
			j = i + 1;
			while (room[j])
			{
				if (!ft_strcmp(room[i], room[j++]))
					ft_error();
			}
		}
		i++;
	}
}

void	ft_pars(t_global *glob)
{
	char	***tunnel;
	char	***room;

	room = ft_pars_room(ft_strsplit(glob->hill, '\n'));
	glob->length = ft_cnt_room(room);
	ft_stock_room(glob, room);
	tunnel = ft_pars_tunnel(glob);
	ft_check_double(glob->room);
	glob->matrice = ft_stock_tunnel(glob, tunnel);
	ft_clear_dbltab(tunnel);
	ft_clear_dbltab(room);
}
