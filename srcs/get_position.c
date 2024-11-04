/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:20:57 by malves-b          #+#    #+#             */
/*   Updated: 2024/08/25 17:07:24 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Funcao que define a posicao de um componente no mapa
*/
void	get_position(char **map, t_position *pos, char component)
{
	int	i;

	i = 0;
	while (map[pos->line])
	{
		while (map[pos->line][pos->col])
		{
			if (map[pos->line][pos->col] == component)
			{
				return ;
			}
			pos->col++;
		}
		pos->line++;
		pos->col = 0;
	}
	return ;
}

// int main(int argc, const char **argv)
// {
//     char **map;
//     char *position;

//     map = read_map((char *)argv[1]);
//     puts(get_position(map, 'P'));
//     return 0;
// }
