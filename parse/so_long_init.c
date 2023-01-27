/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba@student.1337.ma <yrhiba>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:00:55 by yrhiba@stud       #+#    #+#             */
/*   Updated: 2023/01/27 16:44:34 by yrhiba@stud      ###   ########.fr       */
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
	return (dir_init(&((*so_long)->dir)), my_list_init(&((*so_long)->qrc)), 0);
}
