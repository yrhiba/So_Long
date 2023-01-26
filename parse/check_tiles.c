/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba@student.1337.ma <yrhiba>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:23:29 by yrhiba@stud       #+#    #+#             */
/*   Updated: 2023/01/26 19:05:07 by yrhiba@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_requirements(t_so_long *so_long)
{
	if ((so_long->map).map_exit != 1)
		return (-1);
	if ((so_long->map).player_start != 1)
		return (-1);
	if ((so_long->map).collectibles < 1)
		return (-1);
	return (0);
}

static int	calc_tile(t_so_long *so_long, char tile)
{
	if (tile == ES)
		(so_long->map).free_space++;
	else if (tile == WL)
		(so_long->map).walls++;
	else if (tile == CO)
		(so_long->map).collectibles++;
	else if (tile == EX)
		(so_long->map).map_exit++;
	else if (tile == PS)
		return ((so_long->map).player_start++, (so_long->map).free_space++, 0);
	else
		return (-1);
	return (0);
}

int	check_tiles(t_so_long *so_long)
{
	size_t	r;
	size_t	c;

	r = 0;
	while (r < (so_long->map).height)
	{
		c = 0;
		while (c < (so_long->map).width)
		{
			if (((r == 0 || r == ((so_long->map).height - 1)) || (c == 0
						|| c == ((so_long->map).width - 1)))
				&& (so_long->map.map[r][c] != WL))
				return (-1);
			if (calc_tile(so_long, (so_long->map).map[r][c]) == -1)
				return (-1);
			c++;
		}
		r++;
	}
	return (check_requirements(so_long));
}
