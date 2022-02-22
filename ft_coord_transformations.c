/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord_transformations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:15:55 by vellie            #+#    #+#             */
/*   Updated: 2021/11/22 23:15:55 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	new_coord(double x, double y, t_fractol *frac, t_complex *dot)
{	
	newcomp(frac->frame.min_re + (frac->delta.re * (x)), frac->frame.max_im
		 - frac->delta.im * (y), dot);
}

void	delta_generate(t_fractol *frac)
{
	frac->delta.im = (frac->frame.max_im - frac->frame.min_im) / frac->high;
	frac->delta.re = (frac->frame.max_re - frac->frame.min_re) / frac->len;
}

void	move_zoom(t_fractol *frac, int x, int y, double zoom)
{
	t_complex	oldc;

	delta_generate(frac);
	new_coord(x, y, frac, &oldc);
	frac->frame.min_re = oldc.re - (oldc.re - frac->frame.min_re) * zoom;
	frac->frame.max_re = oldc.re + (frac->frame.max_re - oldc.re) * zoom;
	frac->frame.min_im = oldc.im - (oldc.im - frac->frame.min_im) * zoom;
	frac->frame.max_im = oldc.im + (frac->frame.max_im - oldc.im) * zoom;
}

void	newcomp(double x, double y, t_complex *num)
{
	num->re = x;
	num->im = y;
}
