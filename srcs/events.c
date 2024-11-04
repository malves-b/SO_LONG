/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:33:48 by malves-b          #+#    #+#             */
/*   Updated: 2024/11/04 15:01:06 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	c_next(int keycode, t_data *img)
{
	int	new_col;
	int	new_line;

	new_col = img->pos.col;
	new_line = img->pos.line;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		new_col -= 50;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		new_col += 50;
	else if (keycode == KEY_W || keycode == KEY_UP)
		new_line -= 50;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		new_line += 50;
	if (img->map[new_line / 50][new_col / 50] == '1')
		return (0);
	return (1);
}

int	c_exit(t_data *img)
{
	int	l;
	int	c;

	l = 0;
	while (img->map[l])
	{
		c = 0;
		while (img->map[l][c])
		{
			if (img->map[l][c] == 'C')
				return (0);
			c++;
		}
		l++;
	}
	return (1);
}

int	key_press(int keycode, t_data *img)
{
	img->move++;
	if ((keycode == KEY_A || keycode == KEY_LEFT) && c_next(keycode, img))
		img->pos.col -= 50;
	else if ((keycode == KEY_D || keycode == KEY_RIGHT) && c_next(keycode, img))
		img->pos.col += 50;
	else if ((keycode == KEY_W || keycode == KEY_UP) && c_next(keycode, img))
		img->pos.line -= 50;
	else if ((keycode == KEY_S || keycode == KEY_DOWN) && c_next(keycode, img))
		img->pos.line += 50;
	else if (keycode == KEY_ESC)
		finish_game(img);
	else
		return (img->move--);
	ft_putnbr(img->move);
	ft_putchar('\n');
	if (img->map[img->pos.line / 50][img->pos.col / 50] == 'C')
		img->map[img->pos.line / 50][img->pos.col / 50] = '0';
	if (img->map[img->pos.line / 50][img->pos.col / 50] == 'E' && c_exit(img))
		finish_game(img);
	mlx_clear_window(img->mlx, img->mlx_win);
	put_components(img->map, img->mlx, img->mlx_win);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->pos.col,
		img->pos.line);
	return (0);
}

void	finish_game(t_data *img)
{
	if (img->img)
		mlx_destroy_image(img->mlx, img->img);
	if (img->mlx_win)
		mlx_destroy_window(img->mlx, img->mlx_win);
	if (img->mlx)
	{
		mlx_destroy_display(img->mlx);
		free (img->mlx);
	}
	free_args(img->map);
	exit(EXIT_SUCCESS);
}
