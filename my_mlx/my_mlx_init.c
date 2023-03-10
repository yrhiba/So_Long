/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:34:41 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/29 09:19:47 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_imgs(t_so_long *so_long)
{
	if (!(so_long->mlx.imgs.col))
		return (-1);
	if (!(so_long->mlx.imgs.enemy1))
		return (-1);
	if (!(so_long->mlx.imgs.enemy2))
		return (-1);
	if (!(so_long->mlx.imgs.exit_close))
		return (-1);
	if (!(so_long->mlx.imgs.exit_open))
		return (-1);
	if (!(so_long->mlx.imgs.free_space))
		return (-1);
	if (!(so_long->mlx.imgs.player))
		return (-1);
	if (!(so_long->mlx.imgs.wall))
		return (-1);
	return (0);
}

static int	load_images(t_so_long *so_long)
{
	so_long->mlx.imgs.col = mlx_xpm_file_to_image(so_long->mlx.mlx,
			COLLECTIBLE_PATH, &(so_long->map.tile_size),
			&(so_long->map.tile_size));
	so_long->mlx.imgs.player = mlx_xpm_file_to_image(so_long->mlx.mlx,
			PLAYER_PATH, &(so_long->map.tile_size), &(so_long->map.tile_size));
	so_long->mlx.imgs.exit_close = mlx_xpm_file_to_image(so_long->mlx.mlx,
			EXIT_CLOSE_PATH, &(so_long->map.tile_size),
			&(so_long->map.tile_size));
	so_long->mlx.imgs.exit_open = mlx_xpm_file_to_image(so_long->mlx.mlx,
			EXIT_OPEN_PATH, &(so_long->map.tile_size),
			&(so_long->map.tile_size));
	so_long->mlx.imgs.free_space = mlx_xpm_file_to_image(so_long->mlx.mlx,
			FREE_SPACE_PATH, &(so_long->map.tile_size),
			&(so_long->map.tile_size));
	so_long->mlx.imgs.wall = mlx_xpm_file_to_image(so_long->mlx.mlx, WALL_PATH,
			&(so_long->map.tile_size), &(so_long->map.tile_size));
	so_long->mlx.imgs.wall = mlx_xpm_file_to_image(so_long->mlx.mlx, WALL_PATH,
			&(so_long->map.tile_size), &(so_long->map.tile_size));
	so_long->mlx.imgs.enemy1 = mlx_xpm_file_to_image(so_long->mlx.mlx,
			ENEMY1_PATH, &(so_long->map.tile_size), &(so_long->map.tile_size));
	so_long->mlx.imgs.enemy2 = mlx_xpm_file_to_image(so_long->mlx.mlx,
			ENEMY2_PATH, &(so_long->map.tile_size), &(so_long->map.tile_size));
	return (check_imgs(so_long));
}

static size_t	calc_col(t_so_long *sl)
{
	size_t	i;
	size_t	r;
	size_t	c;

	i = 0;
	r = 0;
	while (r < sl->map.height)
	{
		c = 0;
		while (c < sl->map.width)
		{
			if (sl->map.map[r][c++] == CO)
				i++;
		}
		r++;
	}
	return (i);
}

int	my_mlx_init(t_so_long *so_long, void **mlx)
{
	so_long->mlx.mlx = mlx_init();
	if (!((so_long->mlx).mlx))
		return (-1);
	*mlx = so_long->mlx.mlx;
	calc_win_wh(so_long);
	so_long->map.collectibles = calc_col(so_long);
	so_long->mlx.win = mlx_new_window(so_long->mlx.mlx, so_long->mlx.widht,
			so_long->mlx.height, WIN_TITLE);
	if (!(so_long->mlx.win))
		return (-1);
	if (load_images(so_long) == -1)
		return (-1);
	return (put_frame(so_long), 0);
}
