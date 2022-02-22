/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:41:53 by vellie            #+#    #+#             */
/*   Updated: 2021/11/23 00:04:34 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_image(t_fractol *frac)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (!img)
		exit(0);
	img->img = mlx_new_image(frac->init, frac->len, frac->high);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	frac->img = img;
}

void	frame_initialize(t_fractol *frac)
{
	frac->frame.min_im = -1;
	frac->frame.min_re = -2;
	frac->frame.max_im = 1;
	if (frac->type == 1)
		frac->frame.max_re = 1;
	else
		frac->frame.max_re = 2;
}

t_fractol	*create_fractol(int len, int high, char *frac_name, int type)
{
	t_fractol	*frac;

	frac = malloc(sizeof(t_fractol));
	if (!frac)
		error_msg();
	frac->init = mlx_init();
	if (!(frac->init))
		error_msg();
	frac->win = mlx_new_window(frac->init, len, high, frac_name);
	if (!(frac->win))
		error_msg();
	frac->len = len;
	frac->high = high;
	frac->type = type;
	frac->color = 0;
	frac->n = 0;
	frame_initialize(frac);
	create_image(frac);
	return (frac);
}

void	control_frac(t_fractol *frac)
{
	mlx_mouse_hook(frac->win, &mouse_hook, frac);
	mlx_loop_hook(frac->init, &fractal_draw, frac);
	mlx_hook(frac->win, 17, 0, &cross_icon, frac);
	mlx_key_hook(frac->win, &key_hook, frac);
	mlx_loop(frac->init);
}

int	argument_parser(t_fractol *frac, char *arg, int static_arg, t_dot dot)
{
	if (!ft_strcmp(arg, "Mandelbrot"))
		frac = create_fractol((int)LEN_M, (int)HIGH, arg, 1);
	else if (!ft_strcmp(arg, "Julia"))
		frac = create_fractol((int)LEN_J, (int)HIGH, arg, 2);
	else if (!ft_strcmp(arg, "Julia_x3"))
		frac = create_fractol((int)LEN_J, (int)HIGH, arg, 3);
	else
		return (0);
	frac->static_arg = static_arg;
	delta_generate(frac);
	new_coord(dot.x, dot.y, frac, &(frac->static_dot));
	control_frac(frac);
	return (1);
}
