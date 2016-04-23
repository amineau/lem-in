/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 09:27:29 by amineau           #+#    #+#             */
/*   Updated: 2016/04/21 00:06:13 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef struct	s_room t_room;

typedef struct	s_tube
{
	t_room			*room;
	struct s_tube	*next;
}				t_tube;

struct			s_room
{
	int		id;
	char	name;
	int		x;
	int		y;
	int		pos;
	t_tube	*tube;
};

typedef struct	s_ant
{
	int				id;
	t_room			*room;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_global
{
	t_ant	**ant;
	t_room	**room;
	char	*r;
	char	*t;
	int		start;
	int		end;
}				t_global;


t_global    *ft_recovery(void);

int			ft_check_digit(char *str);

void    	ft_error(t_global *glob);
void    	ft_clear(t_global *glob);

void    	ft_listadd_ant(t_ant **begin, int id);
void    	ft_starting_room(t_global *glob);


#endif
