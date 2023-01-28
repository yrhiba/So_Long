/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_win_wh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:36:31 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/28 20:38:19 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calc_win_wh(t_so_long *so_long)
{
	so_long->mlx.widht = so_long->map.width * TILE_SIZE;
	so_long->mlx.height = so_long->map.height * TILE_SIZE;
}
