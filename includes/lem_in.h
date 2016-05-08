/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 09:27:29 by amineau           #+#    #+#             */
/*   Updated: 2016/05/04 16:41:08 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef struct	s_path
{
	int				*path;
	int				size;
	struct s_path	*next;
}				t_path;

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
	char	**room;
	char	*hill;
	char	*com;
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

t_global		*ft_recovery(void);
void			ft_pars(t_global *glob);
t_path			**ft_algo_multi(t_matrice *m, int max_path);
void			ft_moving_ant(t_global *glob, t_path **p);

char			***ft_pars_room(char **tab);
char			***ft_pars_tunnel(t_global *glob);
void			ft_stock_room(t_global *glob, char ***room);
int				**ft_stock_tunnel(t_global *glob, char ***tunnel);

int				ft_check_digit(char *str);
int				ft_check_integer(char *str);
int				ft_max_path(t_ant **ant, t_matrice *m);
int				*ft_tabcpy(int *tab, int length);
int				ft_cnt_ant(t_ant **begin);
void			ft_clear_tab(int *tab, int length);

void			ft_error(void);
void			ft_clear_tabchar(char **tab);
void			ft_clear_ant(t_ant **ant);
void			ft_clear_tabint(int *tab, int length);
void			ft_clear_matrice(t_matrice *m);
void			ft_clear_dbltab(char ***tab);
void			ft_clear_path(t_path **path);
void			ft_clear_glob(t_global *glob);

void			ft_listadd_ant(t_ant **begin, int id);
void			ft_listadd_path(t_path **begin, int *path, int size);
t_path			*ft_listcreate_path(int *path, int size);
void			ft_starting_room(t_ant **ant);

void			ft_display(t_ant **ant, char **list);

#endif