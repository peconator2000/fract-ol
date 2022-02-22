/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_frac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:15:45 by vellie            #+#    #+#             */
/*   Updated: 2021/11/22 23:15:47 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_frac(t_fractol *frac, int x, int y)
{
	t_complex	dot;
	t_complex	z;

	new_coord(x, y, frac, &dot);
	newcomp(0, 0, &z);
	draw_pixel(frac, x, y, how_moves(frac, dot, z));
}

void	julia_frac(t_fractol *frac, int x, int y)
{
	t_complex	dot;
	t_complex	z;

	new_coord(x, y, frac, &z);
	newcomp(frac->static_dot.re, frac->static_dot.im, &dot);
	draw_pixel(frac, x, y, how_moves(frac, dot, z));
}

void	julia3x_frac(t_fractol *frac, int x, int y)
{
	t_complex	dot;
	t_complex	z;

	new_coord(x, y, frac, &z);
	newcomp(frac->static_dot.re, frac->static_dot.im, &dot);
	draw_pixel(frac, x, y, how_bs_moves(frac, dot, z));
}
