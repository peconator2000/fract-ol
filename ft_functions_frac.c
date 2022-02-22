/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_frac.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:16:07 by vellie            #+#    #+#             */
/*   Updated: 2021/11/22 23:27:49 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	how_moves(t_fractol *frac, t_complex dot, t_complex z)
{
	int			n;
	t_complex	res;

	n = 0;
	while (n < (int)STANDART_ACT + frac->n)
	{
		complex_mult(z, z, &res);
		complex_sum(res, dot, &res);
		if (complex_modul(res) > (double)2)
			break ;
		z.im = res.im;
		z.re = res.re;
		n++;
	}
	return (n);
}

int	how_bs_moves(t_fractol *frac, t_complex dot, t_complex z)
{
	int			n;
	t_complex	res;

	n = 0;
	while (n < (int)STANDART_ACT + frac->n)
	{
		complex_mult(z, z, &res);
		complex_mult(z, res, &res);
		complex_sum(res, dot, &res);
		if (complex_modul(res) > (double)2)
			break ;
		z.im = res.im;
		z.re = res.re;
		n++;
	}
	return (n);
}

void	draw_pixel(t_fractol *frac, int x, int y, int moves)
{
	if (moves < (int)STANDART_ACT + frac->n)
		my_mlx_pixel_put(frac->img, x, y, 0xffb6c1 + frac->color + moves * 109);
	else
		my_mlx_pixel_put(frac->img, x, y, 0x6cb9dd9 + frac->color);
}

void	fractal_choice(t_fractol *frac, int x, int y)
{
	if (frac->type == 1)
		mandelbrot_frac(frac, x, y);
	else if (frac->type == 2)
		julia_frac(frac, x, y);
	else if (frac->type == 3)
		julia3x_frac(frac, x, y);
}

int	fractal_draw(t_fractol *frac)
{
	int	x;
	int	y;
	int	curx;
	int	cury;

	x = 0;
	y = 0;
	delta_generate(frac);
	if (frac->static_arg)
	{
		mlx_mouse_get_pos(frac->win, &(curx), &(cury));
		new_coord(curx, cury, frac, &(frac->static_dot));
	}
	while (x < frac->len)
	{
		y = 0;
		while (y < frac->high)
		{
			fractal_choice(frac, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(frac->init, frac->win, frac->img->img, 0, 0);
	return (0);
}
