/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:40:39 by yrhiba@stud       #+#    #+#             */
/*   Updated: 2023/01/29 10:57:27 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	my_destroy_imgs(t_so_long *so_long)
{
	if (so_long->mlx.imgs.col)
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.imgs.col);
	if (so_long->mlx.imgs.enemy1)
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.imgs.enemy1);
	if (so_long->mlx.imgs.enemy2)
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.imgs.enemy2);
	if (so_long->mlx.imgs.exit_close)
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.imgs.exit_close);
	if (so_long->mlx.imgs.exit_open)
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.imgs.exit_open);
	if (so_long->mlx.imgs.free_space)
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.imgs.free_space);
	if (so_long->mlx.imgs.player)
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.imgs.player);
	if (so_long->mlx.imgs.wall)
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.imgs.wall);
}

void	sl_clear(t_so_long **so_long)
{
	my_destroy_imgs(*so_long);
	if ((*so_long)->mlx.win)
		mlx_destroy_window((*so_long)->mlx.mlx, (*so_long)->mlx.win);
	my_list_clear(&((*so_long)->qrc));
	my_list_clear(&((*so_long)->enemys));
	map_clear(*so_long);
	map_visited_clear(*so_long);
	free(*so_long);
	exit(0);
}
