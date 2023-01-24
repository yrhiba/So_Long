/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:06:14 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/24 02:30:26 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isint_con(char *str)
{
	int			is_neg;
	int			i;
	long long	n;

	if (!(*str))
		return (0);
	n = 0;
	i = 0;
	is_neg = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		is_neg = (str[i] == '-');
		i++;
	}
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			n = (n * 10) + (str[i] - '0');
		else
			return (0);
		i++;
	}
	if ((n <= INT_MAX && !is_neg) || (((n - 1) <= INT_MAX) && is_neg))
		return (1);
	return (0);
}

int	ft_isint(char *str)
{
	int	i;
	int	r;

	r = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			r = 1;
			break ;
		}
		i++;
	}
	if (r == 0)
		return (0);
	return (ft_isint_con(str));
}
