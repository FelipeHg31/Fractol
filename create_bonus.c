/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 21:36:36 by juan-her          #+#    #+#             */
/*   Updated: 2025/12/04 18:00:54 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_draw_pixel(t_fractol *fractol, int x, int y)
{
	double	real;
	double	imag;
	int		iter;
	int		color;

	real = map_x(x, fractol);
	imag = map_y(y, fractol);
	if (fractol->fractal_type == JULIA)
		iter = ft_calculate_julia(fractol, real, imag);
	else if (fractol->fractal_type == MANDELBROT)
		iter = ft_calculate_mandel(fractol, real, imag);
	else if (fractol->fractal_type == BOAT)
		iter = ft_calculate_boat(fractol, real, imag);
	else if (fractol->fractal_type == TRICORN)
		iter = ft_calculate_tricorn(fractol, real, imag);
	else
		iter = ERROR;
	color = get_color(iter, fractol->max_iter, fractol->color_shift);
	put_pixel_img(fractol, x, y, color);
}

void	ft_draw(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 1000)
		{
			ft_draw_pixel(fractol, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img_ptr, 0, 0);
}
