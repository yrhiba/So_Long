/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba@student.1337.ma <yrhiba>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:09:20 by yrhiba@stud       #+#    #+#             */
/*   Updated: 2023/01/26 01:56:34 by yrhiba@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_clear_failed_malloc(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	map_clear(t_so_long *so_long)
{
	size_t	i;

	if (!so_long || !((so_long->map).map))
		return ;
	i = 0;
	while (i < so_long->map.height)
	{
		free((so_long->map).map[i]);
		i++;
	}
	free((so_long->map).map);
	(so_long->map).map = 0;
}