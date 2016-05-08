/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:20:20 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 17:57:58 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_length_partone(char **tab)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	start = 0;
	end = 0;
	while (tab[i] && (ft_strchr(tab[i], ' ') || tab[i][0] == '#'))
	{
		if (!ft_strcmp(tab[i], "##start"))
			start++;
		if (!ft_strcmp(tab[i], "##end"))
			end++;
		i++;
	}
	if (start != 1 || end != 1)
		ft_error();
	return (i);
}

char		***ft_pars_room(char **tab)
{
	int		i;
	int		length;
	char	***room;

	length = ft_length_partone(tab);
	if (!(room = (char***)ft_memalloc(sizeof(char**) * (length + 1))))
		ft_error();
	i = -1;
	while (++i < length)
	{
		if (!(room[i] = ft_strsplit(tab[i], ' ')))
			ft_error();
	}
	room[length] = NULL;
	ft_clear_tabchar(tab);
	return (room);
}

int			ft_check_end_room(char **glob_room, char ***room, int i)
{
	while (room[++i] && room[i][0][0] == '#')
		;
	if (room[i])
	{
		if (!(*glob_room = ft_strdup(room[i][0])))
			ft_error();
	}
	else
		ft_error();
	return (i);
}

void		ft_stock_room(t_global *glob, char ***room)
{
	int	i;
	int	id;

	i = 0;
	id = 2;
	if (!(glob->room = (char**)ft_memalloc(sizeof(char*) * glob->length + 1)))
		ft_error();
	while (room[i])
	{
		if (!ft_strcmp(room[i][0], "##start"))
			i = ft_check_end_room(&(glob->room[0]), room, i);
		else if (!ft_strcmp(room[i][0], "##end"))
			i = ft_check_end_room(&(glob->room[1]), room, i);
		else if (room[i][0][0] != '#')
		{
			if (!(glob->room[id++] = ft_strdup(room[i][0])))
				ft_error();
		}
		i++;
	}
	glob->room[id] = NULL;
}
