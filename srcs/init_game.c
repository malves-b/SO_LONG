/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:24:13 by malves-b          #+#    #+#             */
/*   Updated: 2024/11/04 14:33:02 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close(t_data *img)
{
	finish_game(img);
	return (0);
}

void	put_player(void *mlx, void *mlx_win, t_data *img)
{
	int	img_width;
	int	img_height;

	img->img = mlx_xpm_file_to_image(mlx, "img/bird.xpm", &img_width,
			&img_height);
	if (!img->img)
		ft_exit("Is not possible get the image");
	mlx_put_image_to_window(mlx, mlx_win, img->img, img->pos.col,
		img->pos.line);
}

int	init_game(char **map, t_data *img, void *mlx, void **mlx_win)
{
	int	window_width;
	int	window_height;

	window_width = ft_strlen(map[0]) * 50;
	window_height = 0;
	while (map[window_height])
		window_height++;
	window_height *= 50;
	get_position(map, &img->pos, 'P');
	img->pos.line *= 50;
	img->pos.col *= 50;
	put_player(mlx, *mlx_win, img);
	mlx_hook (*mlx_win, 2, 1L << 0, key_press, img);
	mlx_hook (*mlx_win, 17, 0, handle_close, img);
	return (0);
}
