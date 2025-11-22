/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:27:01 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/22 17:32:14 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int ft_calculate(t_fractol *fractol, double x, double y)
{
    double  zr;
    double  zi;
    double  tmp;
    int     i;
    int     max_iter;

    (void)fractol;
    zr = 0;
    zi = 0;
    i = 0;
    max_iter = fractol->max_iter;
    while (((zr * zr) + (zi * zi) < 4) && i < max_iter)
    {
        tmp = (zr * zr) - (zi * zi) + x;
        zi = 2 * zr * zi + y;
        zr = tmp;
        i++;
    }
    return (i);
}

static void ft_draw_pixel(t_fractol *fractol, int x, int y)
{
    double  real;
    double  imag;
    int     iter;
    int     color;
    
    real = map_x(x, fractol);
    imag = map_y(y, fractol);
    iter = ft_calculate(fractol, real, imag);
    color = get_color(iter, fractol->max_iter, fractol->color_shift);
    put_pixel_img(fractol, x, y, color);
}

void    ft_draw_mandel(t_fractol *fractol)
{
    int x;
    int y;

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
}