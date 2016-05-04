/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:18:18 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 16:18:40 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int	ft_cnt_ant(t_ant **begin)
{
	t_ant	*tmp;
	int		cnt;

	tmp = *begin;
	cnt = 0;
	while (tmp)
	{
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

int	ft_cnt_entry(int *tab, int length)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < length)
	{
		if (tab[i++])
			cnt++;
	}
	return (cnt);
}

int	ft_max_path(t_ant **ant, t_matrice *m)
{
	int	tab[3];

	tab[0] = ft_cnt_ant(ant);
	tab[1] = ft_cnt_entry(m->matrice[0], m->length);
	tab[2] = ft_cnt_entry(m->matrice[1], m->length);
	return (ft_min((int*)tab, 3));
}
