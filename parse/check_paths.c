/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:48:18 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/29 00:58:36 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	calc_tile(t_so_long *so_long, t_tile *tile)
{
	if (so_long->map.map[tile->r][tile->c] == CO
		&& (so_long->map).collectibles > 0)
		(so_long->map).collectibles--;
	else if (so_long->map.map[tile->r][tile->c] == EX
			&& (so_long->map).map_exit > 0)
		(so_long->map).map_exit--;
}

static int	queue_add_adj(t_so_long *so_long, t_tile *tile)
{
	t_tile	adj;
	int		d;

	d = -1;
	while (++d < 4)
	{
		adj.c = tile->c + (so_long->dir).dc[d];
		adj.r = tile->r + (so_long->dir).dr[d];
		if ((so_long->map).map[adj.r][adj.c] == WL
			|| (so_long->map).visited[adj.r][adj.c] == WL)
			continue ;
		if (so_long->map.collectibles > 0
			&& (so_long->map).map[adj.r][adj.c] == EX)
			continue ;
		(so_long->map).visited[adj.r][adj.c] = WL;
		if (my_list_push_back(&(so_long->qrc), my_list_new_elem(tiledup(adj.r,
						adj.c))) == -1)
			return (-1);
	}
	return (0);
}

static int	scan_now(t_so_long *so_long)
{
	t_tile	*tile;

	while (!my_list_empty(so_long->qrc))
	{
		tile = (t_tile *)my_list_front(so_long->qrc);
		calc_tile(so_long, tile);
		if (queue_add_adj(so_long, tile) == -1)
			return (-1);
		my_list_pop_front(&(so_long->qrc));
	}
	return (0);
}

static int	scan_using_bfs(t_so_long *so_long)
{
	if (bfs_init_data(so_long) == -1)
		return (-1);
	if (scan_now(so_long) == -1)
		return (-1);
	if (so_long->map.collectibles > 0)
		return (-1);
	if (so_long->map.map_exit == 0)
		return (0);
	map_visited_init_val(so_long);
	my_list_clear(&(so_long->qrc));
	if (bfs_init_data(so_long) == -1)
		return (-1);
	if (scan_now(so_long) == -1)
		return (-1);
	if (so_long->map.map_exit > 0)
		return (-1);
	return (0);
}

int	check_paths(t_so_long *so_long)
{
	if (map_visited_init(so_long) == -1)
		return (-1);
	if (scan_using_bfs(so_long) == -1)
		return (-1);
	return (0);
}
