/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:05:57 by vellie            #+#    #+#             */
/*   Updated: 2021/11/23 00:05:58 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int			res;
	long long	max;
	int			len;

	res = 0;
	max = 0;
	len = ft_strlen(str);
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + *str - 48;
		max = max * 10 + *str - 48;
		str++;
		len--;
	}
	if (len > 0)
		error_msg();
	return (res);
}
