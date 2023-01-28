/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:16:04 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/28 23:34:24 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	parse_so_long(int ac, char **av, t_so_long **so_long)
{
	if (check_map(*so_long, ac, av) == -1)
		return (-1);
	if (check_tiles(*so_long) == -1)
		return (-1);
	if (check_paths(*so_long) == -1)
		return (-1);
	return (0);
}

void f()
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	void		*mlx;
	t_so_long	*so_long;

	atexit(f);
	if (so_long_init(&so_long) == -1)
		return (ft_printf(ERR), 0);
	if (parse_so_long(ac, av, &so_long) == -1)
		return (ft_printf(ERR), sl_clear(&so_long), 0);
	if (my_mlx_init(so_long, &mlx) == -1)
		return (ft_printf(ERR), sl_clear(&so_long), 0);

	// for (size_t	r = 0; r < so_long->map.height; r++)
	// {
	// 	for (size_t c = 0; c < so_long->map.width; c++)
	// 	{
	// 		if (so_long->map.map[r][c] == WL)
	// 			mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win, so_long->mlx.imgs.wall, (c * TILE_SIZE), (r * TILE_SIZE));
	// 		else if (so_long->map.map[r][c] == CO)
	// 			mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win, so_long->mlx.imgs.col, (c * TILE_SIZE), (r * TILE_SIZE));
	// 		else if (so_long->map.map[r][c] == EX)
	// 			mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win, so_long->mlx.imgs.exit_close, (c * TILE_SIZE), (r * TILE_SIZE));
	// 		else if (so_long->map.map[r][c] == PS)
	// 			mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win, so_long->mlx.imgs.player, (c * TILE_SIZE), (r * TILE_SIZE));
	// 		else if (so_long->map.map[r][c] == ES)
	// 			mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win, so_long->mlx.imgs.free_space, (c * TILE_SIZE), (r * TILE_SIZE));
	// 	}
	// }
	// mlx_loop(so_long->mlx.mlx);
	return (sl_clear(&so_long), 0);
}
