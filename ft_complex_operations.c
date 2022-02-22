/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:15:51 by vellie            #+#    #+#             */
/*   Updated: 2021/11/22 23:15:51 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	complex_sum(t_complex num1, t_complex num2, t_complex *res)
{
	res->im = num1.im + num2.im;
	res->re = num1.re + num2.re;
}

void	complex_dif(t_complex num1, t_complex num2, t_complex *res)
{
	res->im = num1.im - num2.im;
	res->re = num1.re - num2.re;
}

void	complex_mult(t_complex num1, t_complex num2, t_complex *res)
{
	res->re = num1.re * num2.re - num1.im * num2.im;
	res->im = num1.re * num2.im + num1.im * num2.re;
}

double	complex_modul(t_complex num)
{
	double	res;

	res = num.im * num.im + num.re * num.re;
	return (sqrt(res));
}

t_complex	positive(t_complex z)
{
	if (z.re < (double)EPS)
		z.re = -z.re;
	if (z.im < (double)EPS)
		z.im = -z.im;
	return (z);
}
