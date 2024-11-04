/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:36:56 by malves-b          #+#    #+#             */
/*   Updated: 2024/08/20 10:40:07 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_collectibles(char **map)
{
	int	collectible;
	int	i;
	int	j;

	collectible = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == COLLECTIBLE)
				collectible++;
			j++;
		}
		j = 0;
		i++;
	}
	return (collectible);
}

int	flood_fill(char **map, int line, int col, int *collectibles)
{
	if (line < 1 || col < 1 || !map[line] || !map[line][col])
		return (0);
	if (map[line][col] == WALL)
		return (0);
	if (map[line][col] == COLLECTIBLE)
		(*collectibles)--;
	if (map[line][col] == EXIT && *collectibles == 0)
		return (1);
	if (map[line][col] != EXIT)
		map[line][col] = WALL;
	if (flood_fill(map, line + 1, col, collectibles)
		|| flood_fill(map, line - 1, col, collectibles)
		|| flood_fill(map, line, col + 1, collectibles)
		|| flood_fill(map, line, col - 1, collectibles))
		return (1);
	return (0);
}

int	check_route(char **map)
{
	int			collectibles;
	t_position	position;

	position.col = 0;
	position.line = 0;
	get_position(map, &position, 'P');
	collectibles = find_collectibles(map);
	return (flood_fill(map, position.line, position.col, &collectibles));
}
