/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba@student.1337.ma <yrhiba>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:16:04 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/25 00:04:50 by yrhiba@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_so_long	*so_long;
	
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Title");

	if (my_so_long_init(&so_long) == -1)
		return (perror("error<1>"), errno);
	mlx_loop(mlx);
	return (0);
}
