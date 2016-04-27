/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 09:27:29 by amineau           #+#    #+#             */
/*   Updated: 2016/04/21 00:06:13 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void    ft_initialize(t_matrice *m, t_global *glob)
{
    m->matrice = glob->matrice;
    m->length = glob->length;
    m->min = m->length + 1;
    m->tmp = (int*)ft_memalloc(sizeof(int) * m->length);
}

int main(void)
{
    t_global    *glob;
    t_matrice   *matrice;
    t_path      **p;
    
    glob = ft_recovery();
    matrice = (t_matrice*)ft_memalloc(sizeof(t_matrice));
    ft_pars(glob);
    ft_starting_room(glob->ant);
    ft_initialize(matrice, glob);
    p = ft_algo_multi(matrice, ft_max_path(glob->ant, matrice));
    ft_moving_ant(glob, p);
	return (0);
}