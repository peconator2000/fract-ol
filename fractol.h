/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellie <vellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:16:37 by vellie            #+#    #+#             */
/*   Updated: 2021/11/23 00:06:26 by vellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx/mlx.h"

# define MAX_OPERATION 2000000000
# define STEP_OPERATION 10
# define STANDART_ACT 200
# define LEN_J 1200
# define LEN_M 900
# define HIGH 600
# define EPS 0.000001
# define MOVE_STEP 50

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_frame
{
	double	max_re;
	double	min_re;
	double	max_im;
	double	min_im;
}				t_frame;

typedef struct s_dot
{
	int	x;
	int	y;
}				t_dot;

typedef struct s_fractol
{
	t_complex	static_dot;
	t_complex	delta;
	t_frame		frame;
	void		*init;
	void		*win;
	int			static_arg;
	int			color;
	int			high;
	int			type;
	int			len;
	int			n;
	t_image		*img;
}				t_fractol;

void			mandelbrot_frac(t_fractol *frac, int x, int y);
void			julia_frac(t_fractol *frac, int x, int y);
void			julia3x_frac(t_fractol *frac, int x, int y);
void			complex_sum(t_complex num1, t_complex num2, t_complex *res);
void			complex_dif(t_complex num1, t_complex num2, t_complex *res);
void			complex_mult(t_complex num1, t_complex num2, t_complex *res);
double			complex_modul(t_complex num);
t_complex		positive(t_complex z);
void			create_image(t_fractol *frac);
void			frame_initialize(t_fractol *frac);
t_fractol		*create_fractol(int len, int high, char *frac_name, int type);
void			control_frac(t_fractol *frac);
int				argument_parser(t_fractol *frac, char *arg, int param, t_dot d);
int				how_moves(t_fractol *frac, t_complex dot, t_complex z);
int				how_bs_moves(t_fractol *frac, t_complex dot, t_complex z);
void			draw_pixel(t_fractol *frac, int x, int y, int moves);
void			fractal_choice(t_fractol *frac, int x, int y);
int				fractal_draw(t_fractol *frac);
int				mouse_hook(int button, int x, int y, t_fractol *frac);
int				key_hook(int keycode, t_fractol *frac);
int				cross_icon(int key);
void			new_coord(double x, double y, t_fractol *frac, t_complex *dot);
void			delta_generate(t_fractol *frac);
void			move_zoom(t_fractol *frac, int x, int y, double zoom);
void			newcomp(double x, double y, t_complex *num);
void			fractol_msg(void);
void			error_msg(void);
int				ft_strcmp(char *s1, char *s2);
void			my_mlx_pixel_put(t_image *data, int x, int y, int color);
int				ft_atoi(char *str);
#endif