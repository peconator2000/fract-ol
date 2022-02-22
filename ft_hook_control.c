/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:16:10 by vellie            #+#    #+#             */
/*   Updated: 2021/11/22 23:16:10 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	delta_step(t_fractol *frac)
{
	return (frac->frame.max_re - frac->frame.min_re);
}

int	mouse_hook(int button, int x, int y, t_fractol *frac)
{
	if (button == 5)
	{
		if (frac->n < (int)MAX_OPERATION)
			frac->n += (int)STEP_OPERATION;
		move_zoom(frac, x, y, 0.8);
	}
	else if (button == 4)
	{
		if (frac->n > -(int)MAX_OPERATION)
			frac->n -= (int)STEP_OPERATION;
		move_zoom(frac, x, y, 1.2);
	}
	return (0);
}

int	key_hook(int keycode, t_fractol *frac)
{
	if (keycode == 53)
	{
		mlx_destroy_window(frac->init, frac->win);
		exit(0);
	}
	else if (keycode == 126)
	{
		frac->color += (int)STANDART_ACT;
	}
	else if (keycode == 125)
	{
		frac->color -= (int)STANDART_ACT;
	}
	else if (keycode == 123)
	{
		frac->frame.max_re -= delta_step(frac) / (int)MOVE_STEP;
		frac->frame.min_re -= delta_step(frac) / (int)MOVE_STEP;
	}
	else if (keycode == 124)
	{
		frac->frame.max_re += delta_step(frac) / (int)MOVE_STEP;
		frac->frame.min_re += delta_step(frac) / (int)MOVE_STEP;
	}
	return (1);
}

int	cross_icon(int key)
{
	(void)key;
	exit(0);
	return (0);
}
