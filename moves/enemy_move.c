/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 09:23:10 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/29 11:46:24 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_dir(t_my_list *it)
{
	if (((t_enemey *)it->data)->count >= 0)
		((t_enemey *)it->data)->dir++;
	else
		((t_enemey *)it->data)->dir--;
	if (((t_enemey *)it->data)->dir > 1)
		((t_enemey *)it->data)->dir = 0;
	if (((t_enemey *)it->data)->dir < 0)
		((t_enemey *)it->data)->dir = 1;
}

static void	pick_dir(size_t *r, size_t *c, t_so_long *sl, t_my_list *it)
{
	int	f;
	int	i;

	f = 1;
	i = 0;
	while (f || sl->map.map[*r][*c] == WL || sl->map.map[*r][*c] == CO
		|| sl->map.map[*r][*c] == EX)
	{
		f = 0;
		*r = ((t_enemey *)it->data)->r
			+ sl->dir.dr[((t_enemey *)it->data)->dir];
		*c = ((t_enemey *)it->data)->c
			+ sl->dir.dc[((t_enemey *)it->data)->dir];
		if (sl->map.map[*r][*c] == WL || sl->map.map[*r][*c] == CO
			|| sl->map.map[*r][*c] == EX)
			change_dir(it);
		i++;
		if (i > 4)
			break ;
	}
}

static int	move_enemeys(t_so_long *sl)
{
	t_my_list	*it;
	size_t		r;
	size_t		c;

	it = sl->enemys;
	while (it)
	{
		pick_dir(&r, &c, sl, it);
		if (sl->map.map[r][c] == PS)
			sl_clear(&sl);
		if (sl->map.map[r][c] != WL && sl->map.map[r][c] != EX
			&& sl->map.map[r][c] != CO)
		{
			sl->map.map[r][c] = OP;
			sl->map.map[((t_enemey *)it->data)->r][((t_enemey *)it->data)->c]
				= ES;
			((t_enemey *)it->data)->r = r;
			((t_enemey *)it->data)->c = c;
			((t_enemey *)it->data)->count++;
			if (((t_enemey *)it->data)->count > 2)
				((t_enemey *)it->data)->count = -3;
		}
		it = it->next;
	}
	return (0);
}

int	enemy_move(t_so_long *sl)
{
	sl->count++;
	sl->count2++;
	if (sl->count > 100)
		sl->count = 0;
	if (sl->count2 > 70)
	{
		sl->count2 = 0;
		move_enemeys(sl);
	}
	my_mlx_put_frame(sl);
	return (0);
}
