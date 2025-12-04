/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:14:30 by juan-her          #+#    #+#             */
/*   Updated: 2025/12/04 18:10:45 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	map_x(int x, t_fractol *fractol)
{
	double	value;

	value = ((x - 1000 / 2) * (4.0 / 1000)) / fractol->zoom + fractol->x_offset;
	return (value);
}

double	map_y(int y, t_fractol *fractol)
{
	double	value;

	value = ((y - 800 / 2) * (4.0 / 800)) / fractol->zoom + fractol->y_offset;
	return (value);
}

void	put_pixel_img(t_fractol *fractol, int x, int y, int color)
{
	int	pixel;

	if (x < 0 || x >= 1000 || y < 0 || y >= 800)
		return ;
	pixel = (y * fractol->size_line) + (x * (fractol->bpp / 8));
	*(unsigned int *)(fractol->img_data + pixel) = color;
}

int	get_color(int iter, int max_iter, int color_shift)
{
	int	red;
	int	green;
	int	blue;

	if (iter >= max_iter)
		return (0x000000);
	red = (iter * (4 + color_shift)) % 256;
	green = (iter * (3 + color_shift)) % 256;
	blue = (iter * (6 + color_shift)) % 256;
	return ((red << 16) | (green << 8) | blue);
}
