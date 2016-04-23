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

int main(void)
{
    t_global    *glob;
    
    glob = ft_recovery();
    
    /********* Test t_ant **********/
    t_ant   *tmp;
    tmp = *(glob->ant);
    while (tmp)
    {
        ft_printf("L%d\n", tmp->id);
        tmp = tmp->next;
    }
    ft_printf(glob->hill);
    /*******************************/
	return (0);
}