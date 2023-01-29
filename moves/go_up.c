/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 04:58:51 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/29 06:08:16 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	go_up(t_so_long *sl)
{
	size_t	r;
	size_t	c;

	ft_printf("going up\n");
	r = sl->player.r + sl->dir.dr[UP];
	c = sl->player.c + sl->dir.dc[UP];
	if (sl->map.map[r][c] == WL)
		return (0);
	if (sl->map.map[r][c] == CO)
		sl->map.collectibles--;
	sl->map.map[r][c] = PS;
	sl->map.map[sl->player.r][sl->player.c] = ES;
	sl->player.c = c;
	sl->player.r = r;
	return (my_mlx_put_frame(sl), 0);
}
