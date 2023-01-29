/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiledup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 02:17:39 by yrhiba@stud       #+#    #+#             */
/*   Updated: 2023/01/29 11:44:53 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*tiledup(size_t r, size_t c)
{
	t_tile	*tile;

	tile = (t_tile *)malloc(sizeof(t_tile));
	if (!tile)
		return ((t_tile *)0);
	return (tile->c = c, tile->r = r, (void *)tile);
}

void	*enemydup(size_t r, size_t c)
{
	t_enemey	*enemy;

	enemy = (t_enemey *)malloc(sizeof(t_enemey));
	if (!enemy)
		return ((t_enemey *)0);
	enemy->count = -3;
	return (enemy->c = c, enemy->r = r, enemy->dir = 0, (void *)enemy);
}
