/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:26:25 by malves-b          #+#    #+#             */
/*   Updated: 2024/09/07 12:37:39 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	int		byte;
	char	c;
	char	*str_buffer;
	int		i;

	i = 0;
	str_buffer = (char *)malloc(10000000);
	if (!str_buffer)
		return (NULL);
	byte = read(fd, &c, 1);
	while (byte > 0)
	{
		str_buffer[i] = c;
		i++;
		if (c == '\n' || c == EOF)
			break ;
		byte = read(fd, &c, 1);
	}
	if (i == 0 || byte < 0)
	{
		free(str_buffer);
		return (NULL);
	}
	str_buffer[i] = '\0';
	return (str_buffer);
}

char	*read_and_concat(int fd)
{
	char	*line;
	char	*aux;
	char	*temp;

	line = get_next_line(fd);
	if (!line)
		aux = NULL;
	else
		aux = ft_strdup("");
	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			free(aux);
			ft_exit("Map countain empty line");
		}
		temp = aux;
		aux = ft_strjoin(temp, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	return (aux);
}

char	**read_map(char *path)
{
	int		fd;
	char	*aux;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_exit("Error open file");
	aux = read_and_concat(fd);
	if (!aux || !aux[0])
		ft_exit("Empty map");
	map = ft_split(aux, '\n');
	free(aux);
	if (!map)
		ft_exit("Error malloc map");
	return (map);
}

// int main(int argc, char const *argv[])
// {
//     int     i;
//     char    **map;

//     i = 0;
//     map = read_map((char *)argv[1]);
//     while (map[i])
//     {
//         puts(map[i]);
//         i++;
//     }
//     i = 0;
//     while (map[i])
//     {
//         free(map[i++]);
//     }
//     free(map);
//     return 0;
// }
