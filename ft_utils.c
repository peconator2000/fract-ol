/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:16:13 by vellie            #+#    #+#             */
/*   Updated: 2021/11/22 23:16:14 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s2 && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	error_msg(void)
{
	write(1, "SOMETHING WENT WRONG\n", 22);
	exit(0);
}

void	fractol_msg(void)
{
	write(1, "YOU CAN SELECT ONE OF FOLLOWED FRACTALS:\n\n", 43);
	write(1, "Mandelbrot\n\nJulia\n\nJulia_x3\n\n", 30);
	exit(0);
}
