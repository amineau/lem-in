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

typedef struct 	s_path
{
	t_room			*room;
	struct s_path	*next;

}				t_path;

struct			s_room
{
	char	*name;
	int		x;
	int		y;
	int		pos;
	t_tube	*tube;
	t_room	*next;
};

typedef struct	s_ant
{
	int				id;
	int				move;
	t_room			*room;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_global
{
	t_ant	**ant;
	t_room	**room;
	char	*hill;
	int		**matrice;
	int		length;
	int		tunnel;
}				t_global;

typedef struct	s_matrice
{
	int	**matrice;
	int	length;
	int	min;
	int	*path_min;
	int	*tmp;
}				t_matrice;


t_global    *ft_recovery(void);
void		ft_pars(t_global *glob);
int			ft_path(t_matrice *m, int id, int cnt);

int			ft_check_digit(char *str);

void    	ft_error(t_global *glob);
void    	ft_clear(t_global *glob);

void    	ft_listadd_ant(t_ant **begin, int id);
void		ft_listadd_room(t_room **begin, char **tab, int pos);
void		ft_listadd_tube(t_room *room, t_room *add);
t_path		*ft_listcreate_path(t_room *room);
void    	ft_starting_room(t_global *glob);

void		ft_display(t_global *glob);

#endif
