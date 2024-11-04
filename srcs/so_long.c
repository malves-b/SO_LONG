/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:11:27 by malves-b          #+#    #+#             */
/*   Updated: 2024/11/04 15:01:10 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	char	**map;
	t_data	img;

	if (argc != 2 || check_args((char *)argv[1]))
		ft_exit("Bad arguments");
	map = read_map((char *)argv[1]);
	img.map = map;
	img.move = 0;
	check_map(map);
	if (check_badcomp(map))
	{
		free_args (map);
		ft_exit ("Bad component");
	}
	img.mlx = mlx_init();
	img.mlx_win = NULL;
	img.pos.col = 0;
	img.pos.line = 0;
	init_map(img.map, img.mlx, &img.mlx_win);
	init_game(img.map, &img, img.mlx, &img.mlx_win);
	mlx_loop(img.mlx);
	free_args(map);
	return (0);
}
