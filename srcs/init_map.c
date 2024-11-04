/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:25:32 by malves-b          #+#    #+#             */
/*   Updated: 2024/11/04 15:01:42 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(void *mlx, void *mlx_win, int col, int line)
{
	void	*wall;
	int		img_width;
	int		img_height;

	wall = mlx_xpm_file_to_image(mlx, "img/block.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, wall, line, col);
	mlx_destroy_image(mlx, wall);
}

void	put_collectible(void *mlx, void *mlx_win, int col, int line)
{
	void	*c;
	int		img_width;
	int		img_height;

	c = mlx_xpm_file_to_image(mlx, "img/cltb.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, c, line, col);
	mlx_destroy_image(mlx, c);
}

void	put_exit(void *mlx, void *mlx_win, int col, int line)
{
	void	*exit;
	int		img_width;
	int		img_height;

	exit = mlx_xpm_file_to_image(mlx, "img/exit.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, exit, line, col);
	mlx_destroy_image(mlx, exit);
}

void	put_components(char **map, void *mlx, void *mlx_win)
{
	int	x;
	int	y;
	int	line_pos;
	int	col_pos;

	x = 0;
	while (map[x])
	{
		y = 0;
		col_pos = x * 50;
		while (map[x][y])
		{
			line_pos = y * 50;
			if (map[x][y] == '1')
				put_wall(mlx, mlx_win, col_pos, line_pos);
			else if (map[x][y] == 'C')
				put_collectible(mlx, mlx_win, col_pos, line_pos);
			else if (map[x][y] == 'E')
				put_exit(mlx, mlx_win, col_pos, line_pos);
			y++;
		}
		x++;
	}
}

void	init_map(char **map, void *mlx, void **mlx_win)
{
	int	x;
	int	y;

	x = (ft_strlen(map[0]) * 50);
	y = 0;
	while (map[y])
		y++;
	y *= 50;
	*mlx_win = mlx_new_window(mlx, x, y, "SO_LONG");
	put_components(map, mlx, *mlx_win);
}
