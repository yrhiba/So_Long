/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:00:55 by yrhiba@stud       #+#    #+#             */
/*   Updated: 2023/01/28 23:17:11 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dir_init(t_dir *dir)
{
	(dir->dc)[0] = 1;
	(dir->dc)[1] = -1;
	(dir->dc)[2] = 0;
	(dir->dc)[3] = 0;
	(dir->dr)[0] = 0;
	(dir->dr)[1] = 0;
	(dir->dr)[2] = -1;
	(dir->dr)[3] = 1;
}

static void	my_mlx_ptr_init(t_so_long *so_long)
{
	so_long->mlx.mlx = NULL;
	so_long->mlx.win = NULL;
	so_long->mlx.imgs.col = NULL;
	so_long->mlx.imgs.player = NULL;
	so_long->mlx.imgs.exit_close = NULL;
	so_long->mlx.imgs.exit_open = NULL;
	so_long->mlx.imgs.wall = NULL;
	so_long->mlx.imgs.free_space = NULL;
	so_long->mlx.imgs.enemy = NULL;
}

int	so_long_init(t_so_long **so_long)
{
	*so_long = (t_so_long *)malloc(sizeof(t_so_long));
	if (!(*so_long))
		return (-1);
	((*so_long)->map).map = (char **)0;
	((*so_long)->map).visited = (char **)0;
	((*so_long)->map).width = 0;
	((*so_long)->map).height = 0;
	((*so_long)->map).walls = 0;
	((*so_long)->map).collectibles = 0;
	((*so_long)->map).free_space = 0;
	((*so_long)->map).map_exit = 0;
	((*so_long)->map).player_start = 0;
	(*so_long)->moves = 0;
	my_mlx_ptr_init(*so_long);
	return (dir_init(&((*so_long)->dir)), my_list_init(&((*so_long)->qrc)), 0);
}
