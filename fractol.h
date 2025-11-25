/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:18:14 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/23 20:49:23 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC 65307
# define ZOOM_IN 65451
# define ZOOM_OUT 65453
# define reset 114
# define COLOR 97
# define ERROR 0;
# define MANDELBROT 1
# define JULIA 2
# define BOAT 3
# define TRICORN 4
# define PLUS 61
# define MINUS 45
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define W 119
# define S 115

typedef struct s_fractol
{
	void    *mlx_ptr;
	void    *win_ptr;
	void    *img_ptr;
	char    *img_data;
	int     fractal_type;
	double  x_offset;
	double	zoom;
	double  y_offset;
	double  c_real;
	double  c_img;
	int     color_shift;
	int     bpp;
	int     size_line;
	int     endian;
	int     max_iter;
}   t_fractol;

int		ft_strcmp(char *str1, char *str2);
double	ft_atof(char *str);
void    ft_initialization(t_fractol *data, char **ag, int ac);
void    ft_create_fractal(t_fractol *fractol);
double	map_x(int x, t_fractol *fractol);
double	map_y(int y, t_fractol *fractol);
void    put_pixel_img(t_fractol *fractol, int x, int y, int color);
int		get_color(int iter, int max_iter, int color_shift);
int		ft_calculate_julia(t_fractol *fractol, double x, double y);
int		ft_calculate_mandel(t_fractol *fractol, double x, double y);
int		ft_calculate_boat(t_fractol *fractol, double x, double y);
int		ft_calculate_tricorn(t_fractol *fractol, double x, double y);
void    ft_draw(t_fractol *fractol);
int		ft_handle_key(int key, t_fractol *fractol);
int		ft_close_window(t_fractol *fractol);

#endif