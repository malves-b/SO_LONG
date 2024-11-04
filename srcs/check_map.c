/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:18:18 by malves-b          #+#    #+#             */
/*   Updated: 2024/08/20 10:33:17 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_isretangular(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (1);
		i++;
	}
	return (0);
}

int	check_walls(char **map)
{
	int	line;
	int	col;
	int	aux;

	line = 0;
	col = 0;
	while (map[line + 1])
		line++;
	while (map[0][col + 1])
		col++;
	aux = col;
	while (col >= 0)
	{
		if (map[line][col] != '1' || map[0][col] != '1')
			return (1);
		col--;
	}
	while (line >= 0)
	{
		if (map[line][aux] != '1' || map[line][0] != '1')
			return (1);
		line--;
	}
	return (0);
}

int	check_components(char **map, int line, int col)
{
	int	found_p;
	int	found_c;
	int	found_e;

	found_p = 0;
	found_c = 0;
	found_e = 0;
	while (map[line])
	{
		col = 0;
		while (map[line][col])
		{
			if (map[line][col] == 'P')
				found_p = 1;
			else if (map[line][col] == 'C')
				found_c = 1;
			else if (map[line][col] == 'E')
				found_e = 1;
			col++;
		}
		line++;
	}
	if (found_p && found_c && found_e)
		return (0);
	return (1);
}

int	check_comp_aux(char **map, int line, int col)
{
	int	found_p;
	int	found_e;

	found_p = 0;
	found_e = 0;
	while (map[line])
	{
		col = 0;
		while (map[line][col])
		{
			if (map[line][col] == 'P')
				found_p++;
			else if (map[line][col] == 'E')
				found_e++;
			col++;
		}
		line++;
	}
	if (found_p > 1 || found_e > 1)
		return (1);
	return (0);
}

int	check_map(char **map)
{
	char	**map_cpy;

	if (check_isretangular(map) || check_walls(map))
	{
		free_args(map);
		ft_exit("Invalid map");
	}
	if (check_components(map, 0, 0) || check_comp_aux(map, 0, 0))
	{
		free_args(map);
		ft_exit("Map: bad components");
	}
	map_cpy = copy_map(map);
	if (!check_route(map_cpy))
	{
		free_args(map_cpy);
		free_args(map);
		ft_exit("Invalid route");
	}
	free_args(map_cpy);
	return (0);
}
