/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:19:35 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 16:19:43 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_display(t_ant **ant, char **list)
{
	t_ant	*tmp;
	int		bol;

	bol = 0;
	tmp = *ant;
	while (tmp)
	{
		if (tmp->move)
		{
			if (bol == 1)
				ft_putchar(' ');
			bol = 1;
			ft_printf("L%d-%s", tmp->id, list[tmp->room]);
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
