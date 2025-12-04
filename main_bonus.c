/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:17:36 by juan-her          #+#    #+#             */
/*   Updated: 2025/12/04 18:10:31 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int ac, char **ag)
{
	t_fractol	fractol;

	if (ac < 2 || ac > 4)
	{
		write (1, "Options:\n-Julia\n-Mandelbort\n-Boat\n-Tricorn\n", 44);
		return (0);
	}
	ft_initialization(&fractol, ag, ac);
	if (!fractol.fractal_type)
	{
		write (1, "Options:\n-Julia\n-Mandelbort\n-Boat\n-Tricorn\n", 44);
		mlx_destroy_display(fractol.mlx_ptr);
		free(fractol.mlx_ptr);
		return (0);
	}
	ft_draw(&fractol);
	mlx_key_hook(fractol.win_ptr, ft_handle_key, &fractol);
	mlx_mouse_hook(fractol.win_ptr, ft_handle_mouse, &fractol);
	mlx_hook(fractol.win_ptr, 17, 0, ft_close_window, &fractol);
	mlx_loop(fractol.mlx_ptr);
}
