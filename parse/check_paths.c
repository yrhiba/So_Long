/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba@student.1337.ma <yrhiba>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:06:42 by yrhiba@stud       #+#    #+#             */
/*   Updated: 2023/01/27 05:05:49 by yrhiba@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	calc_tile(t_so_long *so_long, t_tile *tile)
{
	if ((so_long->map).map[tile->r][tile->c] == CO)
		(so_long->map).collectibles--;
	if ((so_long->map).map[tile->r][tile->c] == EX)
		(so_long->map).map_exit--;
}

static int	scan_using_bfs(t_tile *tile, t_my_list **qrc, t_so_long *so_long)
{
	t_tile	adj;
	size_t	d;

	while (!my_list_empty(*qrc))
	{
		tile = (t_tile *)my_list_front(*qrc);
		calc_tile(so_long, tile);
		d = -1;
		while (++d < 4)
		{
			adj.c = tile->c + (so_long->dir).dc[d];
			adj.r = tile->r + (so_long->dir).dr[d];
			if (((so_long->map).map[adj.r][adj.c] == WL)
				|| (so_long->map).visited[adj.r][adj.c] == 1)
				continue ;
			(so_long->map).visited[adj.r][adj.c] = 1;
			if (my_list_push_back(qrc, my_list_new_elem(tiledup(adj.r,
							adj.c))) == -1)
				return (-1);
		}
		my_list_pop_front(qrc);
	}
	return (0);
}

static int	visited_map_init(t_so_long *so_long)
{
	size_t	r;
	size_t	c;

	(so_long->map).visited = (char **)malloc(sizeof(char)
			* (so_long->map).height);
	if (!((so_long->map).visited))
		return (-1);
	r = -1;
	while (++r < (so_long->map).height)
	{
		(so_long->map).visited[r] = (char *)malloc(sizeof(char)
				* (so_long->map).width);
		if (!((so_long->map).visited[r]))
			return (map_clear_failed_malloc((so_long->map).visited),
				(so_long->map).visited = 0, -1);
		c = -1;
		while (++c < (so_long->map).width)
			(so_long->map).visited[r][c] = 0;
	}
	return (0);
}

int	check_paths(t_so_long *so_long)
{
	t_my_list	*qrc;
	t_tile		tile;

	tile.r = (so_long->player).r;
	tile.c = (so_long->player).c;
	if (my_list_init(&qrc) == -1 || visited_map_init(so_long) == -1)
		return (-1);
	if (my_list_push_back(&qrc, my_list_new_elem(tiledup(tile.r, tile.c)))
		== -1)
		return (-1);
	(so_long->map).visited[tile.r][tile.c] = 1;
	if (scan_using_bfs(&tile, &qrc, so_long) == -1)
		return (my_list_clear(&qrc), -1);
	if ((so_long->map).collectibles != 0 || (so_long->map).map_exit != 0)
		return (my_list_clear(&qrc), -1);
	return (my_list_clear(&qrc), 0);
}
