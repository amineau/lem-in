/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:14:10 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 16:14:28 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*ft_listcreate_path(int *path, int size)
{
	t_path	*p;

	if (!(p = (t_path*)ft_memalloc(sizeof(t_path))))
		ft_error();
	p->size = size;
	p->path = ft_tabcpy(path, size);
	p->next = NULL;
	return (p);
}

void	ft_listadd_path(t_path **begin, int *path, int size)
{
	t_path	*tmp;

	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_listcreate_path(path, size);
}
