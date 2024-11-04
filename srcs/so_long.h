/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:11:38 by malves-b          #+#    #+#             */
/*   Updated: 2024/11/04 15:01:34 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* SEARCH IMG */
/* https://spritedatabase.net/game/3649 */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <math.h>
# include <errno.h>
# include <string.h>

# include "../minilibx-linux/mlx.h" /* remove */

typedef struct position
{
	int	line;
	int	col;
}	t_position;

typedef struct s_data
{
	char		**map;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			move;
	t_position	pos;
}	t_data;

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362

# define KEY_A 97
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115

/* -------------------------------------------------------------------------- */
/*                                 COMPONENTS                                 */
/* -------------------------------------------------------------------------- */

# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXIT 'E'

/* -------------------------------------------------------------------------- */
/*                                    UTILS                                   */
/* -------------------------------------------------------------------------- */

void	ft_exit(char *error_msg);
void	free_args(char **args);
int		check_args(char *map);
char	**read_map(char *path);
void	get_position(char **map, t_position *position, char component);
char	**copy_map(char **map);
void	finish_game(t_data *img);
int		check_badcomp(char **map);

/* -------------------------------------------------------------------------- */
/*                                  CHECK MAP                                 */
/* -------------------------------------------------------------------------- */

int		check_map(char **map);
int		check_route(char **map);
int		flood_fill(char **map, int line, int col, int *collectibles);

/* -------------------------------------------------------------------------- */
/*                                  INIT GAME                                 */
/* -------------------------------------------------------------------------- */

int		init_game(char **map, t_data *img, void *mlx, void **mlx_win);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		draw_images(t_data *img);
int		key_press(int keycode, t_data *img);
void	init_map(char **map, void *mlx, void **mlx_win);
void	put_components(char **map, void *mlx, void *mlx_win);

/* -------------------------------------------------------------------------- */
/*                                   COLORS                                   */
/* -------------------------------------------------------------------------- */

# define GREEN 0x0000FF00
# define RED 0x00FF0000
# define BLUE 0x000000FF

#endif
