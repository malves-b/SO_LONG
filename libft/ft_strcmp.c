/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:00:44 by malves-b          #+#    #+#             */
/*   Updated: 2024/08/06 14:51:58 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *str, char *str2, int size)
{
	int	i;

	i = 0;
	while ((str[i] || str2[i]) && size > 0)
	{
		if (str[i] != str2[i])
			return (0);
		i++;
		size--;
	}
	return (1);
}
