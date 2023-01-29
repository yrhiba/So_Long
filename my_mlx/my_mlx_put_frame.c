/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_put_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 05:42:54 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/29 06:08:09 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile(t_so_long *so_long, size_t r, size_t c)
{
	if (so_long->map.map[r][c] == WL)
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.imgs.wall, (c * TILE_SIZE), (r * TILE_SIZE));
	else if (so_long->map.map[r][c] == CO)
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.imgs.col, (c * TILE_SIZE), (r * TILE_SIZE));
	else if (so_long->map.map[r][c] == EX)
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.imgs.exit_close, (c * TILE_SIZE), (r * TILE_SIZE));
	else if (so_long->map.map[r][c] == PS)
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.imgs.player, (c * TILE_SIZE), (r * TILE_SIZE));
	else if (so_long->map.map[r][c] == ES)
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.imgs.free_space, (c * TILE_SIZE), (r * TILE_SIZE));
	else if (so_long->map.map[r][c] == OP)
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.imgs.enemy, (c * TILE_SIZE), (r * TILE_SIZE));
}

void	put_frame(t_so_long *so_long)
{
	size_t	r;
	size_t	c;

	r = 0;
	while (r < so_long->map.height)
	{
		c = 0;
		while (c < so_long->map.width)
			put_tile(so_long, r, c++);
		r++;
	}
}

int my_mlx_put_frame(t_so_long *sl)
{
	mlx_clear_window(sl->mlx.mlx, sl->mlx.win);
	put_frame(sl);
	return (0);
}
