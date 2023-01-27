/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:18:50 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/27 22:46:35 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	bfs_init_data(t_so_long *so_long)
{
	if (my_list_push_back(&(so_long->qrc),
			my_list_new_elem(tiledup(so_long->player.r,
					so_long->player.c))) == -1)
		return (-1);
	(so_long->map).visited[so_long->player.r][so_long->player.c] = '1';
	return (0);
}
