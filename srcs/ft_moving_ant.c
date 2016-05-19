/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_ant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:18:49 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 16:29:15 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_simple_move(t_ant *ant, int room, int *tab)
{
	tab[ant->room] = 0;
	ant->room = room;
	if (room != 1)
		tab[room] = 1;
}

int		ft_check_disp_room(t_path *p, t_ant *ant, int *tab)
{
	int	i;

	while (p)
	{
		i = 0;
		while (i < p->size)
		{
			if (ant->room == p->path[i])
			{
				ft_simple_move(ant, p->path[i + 1], tab);
				return (1);
			}
			i++;
		}
		p = p->next;
	}
	return (0);
}

int		ft_start_path(t_path *p, t_ant *ant, int *tab, int cnt)
{
	int	size_min;

	if (p->size == 0)
	{
		p = p->next;
		size_min = 1;
	}
	else
		size_min = p->size;
	while (p)
	{
		if (tab[p->path[0]] == 0 && p->size - size_min <= cnt)
		{
			ft_simple_move(ant, p->path[0], tab);
			if (p->size == 1)
				p->size = 0;
			return (1);
		}
		p = p->next;
	}
	return (0);
}

int		ft_check_finish(t_ant **ant)
{
	t_ant	*tmp;

	tmp = *ant;
	while (tmp)
	{
		if (tmp->room != 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_moving_ant(t_global *glob, t_path **p)
{
	int		tab[glob->length];
	int		cnt_ant;
	t_ant	*ant;

	ft_clear_tabint(tab, glob->length);
	cnt_ant = ft_cnt_ant(glob->ant);
	while (!ft_check_finish(glob->ant))
	{
		if ((*p)->size == 0)
			(*p)->size = 1;
		ant = *(glob->ant);
		while (ant)
		{
			if (ant->room == 0)
				ant->move = ft_start_path(*p, ant, tab, cnt_ant - ant->id);
			else if (ant->room != 1)
				ant->move = ft_check_disp_room(*p, ant, tab);
			else
				ant->move = 0;
			ant = ant->next;
		}
		ft_display(glob->ant, glob->room);
	}
}
