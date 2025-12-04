/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:48:34 by juan-her          #+#    #+#             */
/*   Updated: 2025/12/04 18:10:55 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_set_julia(t_fractol *data, char **ag, int ac)
{
	if (ac == 4)
	{
		if (!ft_check_number(ag[2], data) || !ft_check_number(ag[3], data))
			return ;
		data->c_real = ft_atof(ag[2]);
		data->c_img = ft_atof(ag[3]);
		if (data->c_real < -2.0 || data->c_real > 2.0)
			data->c_real = -0.7;
		if (data->c_img < -2.0 || data->c_img > 2.0)
			data->c_img = 0.27015;
	}
	else if (ac == 3)
	{
		if (!ft_check_number(ag[2], data))
			return ;
		data->c_real = ft_atof(ag[2]);
		if (data->c_real < -2.0 || data->c_real > 2.0)
			data->c_real = -0.7;
		data->c_img = 0.27015;
	}
	else
	{
		data->c_img = 0.27015;
		data->c_real = -0.7;
	}
}

static void	ft_parsing(t_fractol *data, char **ag, int ac)
{
	if (!ag[1])
		data->fractal_type = ERROR;
	if (ft_strcmp(ag[1], "julia"))
	{
		data->fractal_type = JULIA;
		ft_set_julia(data, ag, ac);
	}
	else if (ft_strcmp(ag[1], "mandelbrot") && ac == 2)
		data->fractal_type = MANDELBROT;
	else if (ft_strcmp(ag[1], "boat") && ac == 2)
		data->fractal_type = BOAT;
	else if (ft_strcmp(ag[1], "tricorn") && ac == 2)
		data->fractal_type = TRICORN;
	else
		data->fractal_type = ERROR;
}

static void	ft_init_img(t_fractol *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1000, 800);
	if (!data->img_ptr)
	{
		data->fractal_type = ERROR;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		return ;
	}
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->size_line, &data->endian);
	if (!data->img_data)
	{
		data->fractal_type = ERROR;
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		return ;
	}
}

void	ft_initialization(t_fractol *data, char **ag, int ac)
{
	data->x_offset = 0;
	data->y_offset = 0;
	data->color_shift = 240;
	data->fractal_type = ERROR;
	data->max_iter = 100;
	data->zoom = 1.0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		data->fractal_type = ERROR;
		return ;
	}
	ft_parsing(data, ag, ac);
	if (data->fractal_type)
	{
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 800, "fractol");
		if (!data->win_ptr)
		{
			data->fractal_type = ERROR;
			return ;
		}
		ft_init_img(data);
	}
}
