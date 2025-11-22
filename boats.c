/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:30:36 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/22 21:25:27 by juan-her         ###   ########.fr       */
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
    zr = 0.0;
    zi = 0.0;
    i = 0;
    fractol->c_real = (x / fractol->zoom) + fractol->x_offset;
    fractol->c_img = (y / fractol->zoom) + fractol->y_offset;
    max_iter = fractol->max_iter;
    while (((zr * zr) + (zi * zi) <= 4) && i < max_iter)
    {
        tmp = zr * zr - zi * zi + fractol->c_real;
        zi = fabs(2 * zr * zi) + fractol->c_img;
        zr = fabs(tmp);
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

void    ft_draw_boat(t_fractol *fractol)
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