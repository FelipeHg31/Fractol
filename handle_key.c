/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:30:29 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/22 21:54:34 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void ft_handle_move(int key, t_fractol *fractol)
{
    if (fractol->fractal_type == JULIA)
    {
        if (key == UP)
            fractol->c_img += 0.05;
        else if (key == DOWN)
            fractol->c_img -= 0.05;
        if (key == RIGHT)
            fractol->c_real += 0.05;
        else if (key == LEFT)
            fractol->c_real -= 0.05;
    }
    else
    {
        if (key == UP)
            fractol->y_offset += 0.1 / fractol->zoom;
        else if (key == DOWN)
            fractol->y_offset -= 0.1 / fractol->zoom;
        if (key == LEFT)
            fractol->x_offset += 0.1 / fractol->zoom;
        else if (key == RIGHT)
            fractol->x_offset -= 0.1 / fractol->zoom;
    }
}

static void ft_handle_zoom(int key, t_fractol *fractol)
{
    if (key == ZOOM_IN)
    {
        fractol->zoom *= 1.1;
        fractol->max_iter += 10;
    }
    else if (key == ZOOM_OUT)
    {
        fractol->zoom /= 1.1;
        if (fractol->max_iter > 30)
            fractol->max_iter -= 10;
    }
    ft_draw(fractol);
}

static void ft_change_color(int key, t_fractol *fractol)
{
    if (key == COLOR)
        fractol->color_shift += 31;
}

int ft_handle_key(int key, t_fractol *fractol)
{
    if (key == ESC)
    {
        mlx_destroy_image(fractol->mlx_ptr, fractol->img_ptr);
        mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
        mlx_destroy_display(fractol->mlx_ptr);
        free(fractol->mlx_ptr);
        exit(0);
    }
    ft_handle_move(key, fractol);
    ft_handle_zoom(key, fractol);
    ft_change_color(key, fractol);
    ft_draw(fractol);
    return (0);
}

int ft_close_window(t_fractol *fractol)
{
    mlx_destroy_image(fractol->mlx_ptr, fractol->img_ptr);
    mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
    mlx_destroy_display(fractol->mlx_ptr);
    free(fractol->mlx_ptr);
    exit(0);
}