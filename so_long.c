/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:16:04 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/29 03:39:52 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	parse_so_long(int ac, char **av, t_so_long **so_long)
{
	if (check_av(ac, av) == -1)
		return (-1);
	if (check_map(*so_long, ac, av) == -1)
		return (-1);
	if (check_tiles(*so_long) == -1)
		return (-1);
	if (check_paths(*so_long) == -1)
		return (-1);
	return (0);
}

static void	f(void)
{
	system("leaks so_long");
}

static int	key_press(int keycode, t_so_long *sl)
{
	if (keycode == ESC)
		sl_clear(&sl);
	mlx_clear_window(sl->mlx.mlx, sl->mlx.win);
	mlx_string_put(sl->mlx.mlx, sl->mlx.win, 0, 0, 255, "hello");
	return (0);
}

static int	mouse_press(int code, int x, int y, t_so_long *sl)
{
	if ((code == 1 || code == 2 || code == 3) && (x < 50 || y < 50
			|| x > (sl->mlx.widht - 50) || y > (sl->mlx.height - 50)))
		sl_clear(&sl);
	return (0);
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
	mlx_key_hook(so_long->mlx.win, key_press, so_long);
	mlx_mouse_hook(so_long->mlx.win, mouse_press, so_long);
	mlx_loop(so_long->mlx.mlx);
	return (sl_clear(&so_long), 0);
}
