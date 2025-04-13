/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:38:12 by sara              #+#    #+#             */
/*   Updated: 2025/04/12 18:01:35 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "mlx.h"

# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include <limits.h>

typedef struct s_long
{
	size_t	h;
	size_t	l;
	int		y;
	int		x;
	int		paw;
	int		exit;
	char	**dmap;//fooldfill, backtracking, check valid map
	char	**base;//main map
	int		getpaw;
}			t_long;

typedef struct s_play
{
	void	*mlx;
	void	*win;
	t_long	map;
	void	*player;
	void	*wall;
	void	*floor;
	void	*coll;
	void	*exit;
	int		moves;
}	t_play;

int		pe(t_long *map);
int		pe(t_long *map);
int		sign(t_long *map);
void	freemtx(char **mxt);
int		check_c(t_long *map);
int		check_c(t_long *map);
void	find_pos(t_long *map);
int		check_open(char *file);
int		check_wall(t_long *map);
int		count_line(char *str, t_long *map);
char	**readmap(char *file, t_long *map);
char	**copy_map(char *file, t_long *map);
int		check_all(char *file, t_long *map);
int		valid_map(char *file, t_long *map);
int		back_tracking(int x, int y, t_long *map);
int		search_pos(size_t x, size_t y, t_long *map);
int		search_pos(size_t x, size_t y, t_long *map);
void dest_win(t_play *play);
void    dest_img(t_play *play);
int	move_check(t_play *play, size_t n_x, size_t n_y);
void exit_win(t_play *play);
int cls_win(t_play *play);
int	img_check(char *file);
void *creat_textu(void *mlx, char *path, t_play *play);
void	place_img(t_play *play);
void	map_load(t_play *play);
int key_hook(int keycd, t_play *play);
void	mv_player(t_play *play, size_t n_x, size_t n_y);
void	img_win(t_play *play, size_t x, size_t y);

#endif
