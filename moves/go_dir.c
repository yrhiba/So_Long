/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 04:58:51 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/29 11:50:58 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	go_dir(t_so_long *sl, int dir)
{
	size_t	r;
	size_t	c;

	r = sl->player.r + sl->dir.dr[dir];
	c = sl->player.c + sl->dir.dc[dir];
	if (sl->map.map[r][c] == WL)
		return (0);
	if (sl->map.map[r][c] == EX)
	{
		if (sl->map.collectibles == 0)
			sl_clear(&sl);
		return (0);
	}
	if (sl->map.map[r][c] == CO)
		sl->map.collectibles--;
	if (sl->map.map[r][c] == OP)
		sl_clear(&sl);
	sl->map.map[r][c] = PS;
	sl->map.map[sl->player.r][sl->player.c] = ES;
	sl->player.c = c;
	sl->player.r = r;
	return (sl->moves++, my_mlx_put_frame(sl), 0);
}
