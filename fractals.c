/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 21:36:01 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/22 22:09:51 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_calculate_julia(t_fractol *fractol, double x, double y)
{
    double  zr;
    double  zi;
    double  tmp;
    int     i;

    zr = x;
    zi = y;
    i = 0;
    while (((zr * zr) + (zi * zi) < 4) && i < fractol->max_iter)
    {
        tmp = (zr * zr) - (zi * zi) + fractol->c_real;
        zi = 2 * zr * zi + fractol->c_img;
        zr = tmp;
        i++;
    }
    return (i);
}

int ft_calculate_mandel(t_fractol *fractol, double x, double y)
{
    double  zr;
    double  zi;
    double  tmp;
    int     i;

    (void)fractol;
    zr = 0;
    zi = 0;
    i = 0;
    while (((zr * zr) + (zi * zi) < 4) && i < fractol->max_iter)
    {
        tmp = (zr * zr) - (zi * zi) + x;
        zi = 2 * zr * zi + y;
        zr = tmp;
        i++;
    }
    return (i);
}

int ft_calculate_boat(t_fractol *fractol, double x, double y)
{
    double  zr;
    double  zi;
    double  tmp;
    int     i;

    (void)fractol;
    zr = 0.0;
    zi = 0.0;
    i = 0;
    fractol->c_real = (x / fractol->zoom) + fractol->x_offset;
    fractol->c_img = (y / fractol->zoom) + fractol->y_offset;
    while (((zr * zr) + (zi * zi) <= 4) && i < fractol->max_iter)
    {
        tmp = zr * zr - zi * zi + fractol->c_real;
        zi = fabs(2 * zr * zi) + fractol->c_img;
        zr = fabs(tmp);
        i++;
    }
    return (i);
}

int ft_calculate_tricorn(t_fractol *fractol, double x, double y)
{
    double tmp;
    double zr;
    double zi;
    int i;
    
    i = 0;
    zr = 0;
    zi = 0;
    fractol->c_real = (x / fractol->zoom) + fractol->x_offset;
    fractol->c_img = (y / fractol->zoom) + fractol->y_offset;
    while (((zr * zr) + (zi * zi) <= 4) && i < fractol->max_iter)
    {
        tmp = zr * zr - zi * zi + fractol->c_real;
        zi = -2 * zr * zi + fractol->c_img;
        zr = tmp;
        i++;
    }
    return (i);
}