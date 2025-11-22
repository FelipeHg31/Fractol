/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:14:30 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/22 16:22:22 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_create_fractal(t_fractol *fractol)
{
    if (fractol->fractal_type == MANDELBROT)
        ft_draw_mandel(fractol);
    else if (fractol->fractal_type == JULIA)
        ft_draw_julia(fractol);
    mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->img_ptr, 0, 0);
}

double map_x(int x, t_fractol *fractol)
{
    return (((x - 1000 / 2) * (4.0 / 1000)) / (fractol->zoom + fractol->x_offset));
}

double map_y(int y, t_fractol *fractol)
{
    return (((y - 800 / 2) * (4.0 / 800)) / (fractol->zoom + fractol->y_offset));
}

void    put_pixel_img(t_fractol *fractol, int x, int y, int color)
{
    int pixel;

    if (x < 0 || x >= 1000 || y < 0 || y >= 800)
        return ;
    pixel = (y * fractol->size_line) + (x * (fractol->bpp / 8));
    *(unsigned int *)(fractol->img_data + pixel) = color;
}

int get_color(int iter, int max_iter, int color_shift)
{
    int red;
    int green;
    int blue;

    if (iter >= max_iter)
        return (0x000000);
    red = (iter * (9 + color_shift)) % 256;
    green = (iter * (5 + color_shift)) % 256;
    blue = (iter * (11 + color_shift)) % 256;
    return ((red << 16) | (green << 8) | blue);
}