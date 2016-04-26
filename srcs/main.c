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
    ft_pars(glob);
    ft_starting_room(glob);
    ft_path(glob->matrice, glob->length, 0, 0);


    /******** Test Matrice *********/
    ft_printf("****************************Matrice*****************************\n");
    int i = 0;
    int j;
    ft_printf("   ");
    while (i < glob->length)
        ft_printf("%2d ", i++);
    ft_printf("\n");
    i = 0;
    while (i < glob->length)
    {
        j = 0;
        ft_printf("%2d ", i);
        while (j < glob->length)
            ft_printf("%2d ", glob->matrice[i][j++]);
        i++;
        ft_printf("\n");
    }
    /******** Test t_ant *********/
    t_ant   *tmp;
    tmp = *(glob->ant);
    while (tmp)
    {
        ft_printf("L%d-%s-%d", tmp->id, tmp->room->name, tmp->move);
        if (tmp->next)
            ft_putchar(' ');
        else
            ft_putchar('\n');
        tmp = tmp->next;
    }
    /*******************************/
	return (0);
}