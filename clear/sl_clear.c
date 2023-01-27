/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:40:39 by yrhiba@stud       #+#    #+#             */
/*   Updated: 2023/01/27 22:47:35 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_clear(t_so_long **so_long)
{
	my_list_clear(&((*so_long)->qrc));
	map_clear(*so_long);
	map_visited_clear(*so_long);
	free(*so_long);
}
