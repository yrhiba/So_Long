/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_visited_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:12:57 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/27 22:13:41 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_visited_init(t_so_long *so_long)
{
	char	**map;
	size_t	r;
	size_t	c;

	map = (char **) malloc(sizeof(char *) * so_long->map.height);
	if (!map)
		return (-1);
	r = 0;
	while (r < so_long->map.height)
	{
		map[r] = (char *)malloc(sizeof(char) * (so_long->map).width);
		if (!(map[r]))
			return (map_clear_failed_malloc(map), -1);
		c = 0;
		while (c < (so_long->map).width)
			map[r][c++] = '0';
		r++;
	}
	return ((so_long->map).visited = map, 0);
}
