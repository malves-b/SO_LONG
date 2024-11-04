/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:15:18 by malves-b          #+#    #+#             */
/*   Updated: 2024/09/07 13:57:36 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *error_msg)
{
	perror(error_msg);
	exit(EXIT_FAILURE);
}

/* -------------------------------------------------------------------------- */

int	check_args(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i -= 4;
	if (!ft_strcmp(map + i, ".ber", 4))
	{
		perror ("Map: invalid format");
		exit(EXIT_FAILURE);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}
/* -------------------------------------------------------------------------- */

char	**copy_map(char **map)
{
	char	**map_cpy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	map_cpy = ft_calloc(sizeof(char *), i + 1);
	if (!map_cpy)
		ft_exit("map_cpy: malloc");
	i = 0;
	while (map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (!map_cpy[i])
		{
			while (i > 0)
				free(map_cpy[--i]);
			free(map_cpy);
			ft_exit("map_cpy[i]: malloc");
		}
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int	check_badcomp(char **map)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (map[line])
	{
		col = 0;
		while (map[line][col])
		{
			if (map[line][col] != '0' && map[line][col] != '1')
			{
				if (map[line][col] != 'C' && map[line][col] != 'E')
				{
					if (map[line][col] != 'P')
						return (1);
				}
			}
			col++;
		}
		line++;
	}
	return (0);
}
