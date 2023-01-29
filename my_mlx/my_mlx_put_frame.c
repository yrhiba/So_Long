/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_put_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 05:42:54 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/29 12:08:31 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_op(t_so_long *sl, size_t c, size_t r)
{
	if (sl->count > 50)
		mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win,
			sl->mlx.imgs.enemy1, (c * TILE_SIZE), (r * TILE_SIZE));
	else
		mlx_put_image_to_window(sl->mlx.mlx, sl->mlx.win,
			sl->mlx.imgs.enemy2, (c * TILE_SIZE), (r * TILE_SIZE));
}

static void	put_tile(t_so_long *so_long, size_t r, size_t c)
{
	if (so_long->map.map[r][c] == WL)
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.imgs.wall, (c * TILE_SIZE), (r * TILE_SIZE));
	else if (so_long->map.map[r][c] == CO)
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.imgs.col, (c * TILE_SIZE), (r * TILE_SIZE));
	else if (so_long->map.map[r][c] == EX)
	{
		if (so_long->map.collectibles > 0)
			mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
				so_long->mlx.imgs.exit_close, (c * TILE_SIZE), (r * TILE_SIZE));
		else
			mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
				so_long->mlx.imgs.exit_open, (c * TILE_SIZE), (r * TILE_SIZE));
	}
	else if (so_long->map.map[r][c] == PS)
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.imgs.player, (c * TILE_SIZE), (r * TILE_SIZE));
	else if (so_long->map.map[r][c] == ES)
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.imgs.free_space, (c * TILE_SIZE), (r * TILE_SIZE));
	else if (so_long->map.map[r][c] == OP)
		put_op(so_long, c, r);
}

void	put_moves(t_so_long *so_long, int x, int y)
{
	char	*m;

	m = ft_sprintf("%d", so_long->moves);
	mlx_string_put(so_long->mlx.mlx, so_long->mlx.win, x, y, 0xfffff, m);
	free(m);
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
	put_moves(so_long, (so_long->free_tile.c * 100) + 10,
		(so_long->free_tile.r * 100) + 10);
}

int	my_mlx_put_frame(t_so_long *sl)
{
	mlx_clear_window(sl->mlx.mlx, sl->mlx.win);
	put_frame(sl);
	return (0);
}
