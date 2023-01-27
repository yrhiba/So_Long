/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiledup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba@student.1337.ma <yrhiba>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 02:17:39 by yrhiba@stud       #+#    #+#             */
/*   Updated: 2023/01/27 04:12:48 by yrhiba@stud      ###   ########.fr       */
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
