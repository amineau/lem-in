/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:22:39 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 16:22:47 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	*ft_tabcpy(int *tab, int length)
{
	int	i;
	int	*new;

	i = 0;
	if (!(new = (int*)ft_memalloc(sizeof(int) * length)))
		ft_error();
	while (i < length)
	{
		new[i] = tab[i];
		i++;
	}
	return (new);
}
