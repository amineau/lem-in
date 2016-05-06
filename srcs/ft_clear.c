/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:12:14 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 16:12:53 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_clear_matrice(t_matrice *m)
{
	int	i;

	i = 0;
	while (i < m->length)
		free(m->matrice[i++]);
	free(m->matrice);
	free(m->path_min);
	free(m->tmp);
	free(m);
}

void	ft_clear_ant(t_ant **ant)
{
	t_ant	*tmp;
	t_ant	*rem;

	tmp = *ant;
	while (tmp)
	{
		rem = tmp;
		tmp = tmp->next;
		free(rem);
	}
	free(ant);
}

void	ft_clear_path(t_path **path)
{
	t_path	*tmp;
	t_path	*rem;

	tmp = *path;
	while (tmp)
	{
		free(tmp->path);
		rem = tmp;
		tmp = tmp->next;
		free(rem);
	}
	free(path);
}

void	ft_clear_tabint(int *tab, int length)
{
	int	i;

	i = 0;
	while (i < length)
		tab[i++] = 0;
}

void	ft_clear_tabchar(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
}
