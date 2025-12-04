/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:30:29 by juan-her          #+#    #+#             */
/*   Updated: 2025/12/04 18:01:43 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_handle_move(int key, t_fractol *fractol)
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
			fractol->y_offset -= 0.05 / fractol->zoom;
		else if (key == DOWN)
			fractol->y_offset += 0.05 / fractol->zoom;
		if (key == LEFT)
			fractol->x_offset -= 0.05 / fractol->zoom;
		else if (key == RIGHT)
			fractol->x_offset += 0.05 / fractol->zoom;
	}
	ft_draw(fractol);
}

static void	ft_change_color(int key, t_fractol *fractol)
{
	if (key == COLOR)
		fractol->color_shift += 31;
	ft_draw(fractol);
}

int	ft_handle_mouse(int button, int x, int y, t_fractol *fractol)
{
	double	mouse_move_after[2];
	double	zoomc;

	if (button == 4 || button == 5)
	{
		mouse_move_after[0] = map_x(x, fractol);
		mouse_move_after[1] = map_y(y, fractol);
		if (button == 4)
		{
			fractol->max_iter += 10;
			zoomc = 1.1;
		}
		else
		{
			fractol->max_iter -= 10;
			zoomc = 0.9;
		}
		fractol->zoom *= zoomc;
		fractol->x_offset -= map_x(x, fractol) - mouse_move_after[0];
		fractol->y_offset -= map_y(y, fractol) - mouse_move_after[1];
		ft_draw(fractol);
	}
	return (0);
}

int	ft_handle_key(int key, t_fractol *fractol)
{
	if (key == ESC)
	{
		mlx_destroy_image(fractol->mlx_ptr, fractol->img_ptr);
		mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
		exit(0);
	}
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		ft_handle_move(key, fractol);
	else if (key == COLOR)
		ft_change_color(key, fractol);
	return (0);
}

int	ft_close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_ptr, fractol->img_ptr);
	mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
	mlx_destroy_display(fractol->mlx_ptr);
	free(fractol->mlx_ptr);
	exit(0);
}
