/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:11:40 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 16:12:02 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_initialize(t_matrice *m, t_global *glob)
{
	m->matrice = glob->matrice;
	m->length = glob->length;
	m->min = m->length + 1;
	m->tmp = (int*)ft_memalloc(sizeof(int) * m->length);
}

int		main(void)
{
	t_global	*glob;
	t_matrice	*matrice;
	t_path		**p;

	glob = ft_recovery();
	matrice = (t_matrice*)ft_memalloc(sizeof(t_matrice));
	ft_pars(glob);
	ft_starting_room(glob->ant);
	ft_initialize(matrice, glob);
	p = ft_algo_multi(matrice, ft_max_path(glob->ant, matrice));
	ft_putstr(glob->com);
	ft_putnbrendl(ft_cnt_ant(glob->ant));
	ft_putendl(glob->hill);
	ft_moving_ant(glob, p);
	ft_clear_path(p);
	ft_clear_glob(glob);
	return (0);
}
