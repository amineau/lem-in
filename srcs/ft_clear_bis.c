/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:19:57 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 16:20:03 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_clear_dbltab(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_clear_tabchar(tab[i++]);
	free(tab);
}

void	ft_clear_glob(t_global *glob)
{
	ft_clear_ant(glob->ant);
	ft_clear_tabchar(glob->room);
	ft_strdel(&(glob->hill));
	ft_strdel(&(glob->com));
	free(glob);
}
