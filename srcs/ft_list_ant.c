/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:13:22 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 16:26:34 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_starting_room(t_ant **ant)
{
	t_ant	*tmp;

	tmp = *ant;
	while (tmp)
	{
		tmp->room = 0;
		tmp->move = 0;
		tmp = tmp->next;
	}
}

t_ant	*ft_listcreate_ant(int id)
{
	t_ant	*ant;

	if (!(ant = (t_ant*)ft_memalloc(sizeof(t_ant))))
		ft_error();
	ant->id = id;
	ant->next = NULL;
	return (ant);
}

void	ft_listadd_ant(t_ant **begin, int id)
{
	t_ant	*tmp;

	if ((tmp = *begin))
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_listcreate_ant(id);
	}
	else
		*begin = ft_listcreate_ant(id);
}
