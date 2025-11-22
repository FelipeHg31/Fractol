/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:18:14 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/22 15:27:08 by juan-her         ###   ########.fr       */
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

#endif