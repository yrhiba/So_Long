/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:09:20 by yrhiba@stud       #+#    #+#             */
/*   Updated: 2023/01/28 00:40:24 by yrhiba           ###   ########.fr       */
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

	if (!((so_long->map).map))
		return ;
	i = 0;
	while (i < so_long->map.height)
		free(((so_long->map).map[i++]));
	free(((so_long->map).map));
}

void	map_visited_clear(t_so_long *so_long)
{
	size_t	i;

	if (!((so_long->map).visited))
		return ;
	i = 0;
	while (i < so_long->map.height)
		free(((so_long->map).visited[i++]));
	free(((so_long->map).visited));
}
