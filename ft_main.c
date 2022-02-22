/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:16:17 by vellie            #+#    #+#             */
/*   Updated: 2021/11/23 00:11:00 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*frac;
	t_dot		cur;

	frac = NULL;
	if (argc == 1)
		fractol_msg();
	else if (argc == 2)
	{
		cur.x = 0;
		cur.y = 0;
		if (!argument_parser(frac, argv[1], 1, cur))
			fractol_msg();
	}
	else if (argc == 4)
	{
		cur.x = ft_atoi(argv[2]);
		cur.y = ft_atoi(argv[3]);
		if (!argument_parser(frac, argv[1], 0, cur))
			fractol_msg();
	}
	else
		fractol_msg();
	return (0);
}
