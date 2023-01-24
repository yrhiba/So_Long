/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:30:27 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/13 11:07:23 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_sprintf(const char *format, ...)
{
	t_print	*tab;
	void	*f;
	int		i;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab || !format)
		return (free(tab), NULL);
	tab->buff = (char *)ft_calloc(1, sizeof(char));
	if (!tab->buff)
		return (free(tab), NULL);
	tab->buflen = 0;
	va_start(tab->args, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_format(format, i, tab);
		else
			ft_addchar(tab, (char)*(format + i));
		if (tab->error == 1)
			return (free(tab->buff), free(tab), NULL);
	}
	return (f = tab->buff, va_end(tab->args), free(tab), f);
}
