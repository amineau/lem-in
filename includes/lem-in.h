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
	int				*path;
	int				size;
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
	int				room;
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
t_path		**ft_algo_multi(t_matrice *m, int max_path);
void		ft_moving_ant(t_global *glob, t_path **p);

int			ft_check_digit(char *str);
int			ft_max_path(t_ant **ant, t_matrice *m);
int			*ft_tabcpy(int *tab, int length);
void    	ft_clear_tab(int *tab, int length);

void    	ft_error(t_global *glob);
void    	ft_clear(t_global *glob);

void    	ft_listadd_ant(t_ant **begin, int id);
void		ft_listadd_room(t_room **begin, char **tab, int pos);
void		ft_listadd_tube(t_room *room, t_room *add);
void    	ft_listadd_path(t_path **begin, int *path, int size);
t_path   	*ft_listcreate_path(int *path, int size);
void		ft_starting_room(t_ant **ant);

void		ft_display(t_ant **ant);

#endif
