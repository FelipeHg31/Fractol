/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:17:36 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/22 15:15:35 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **ag)
{
    t_fractol fractol;
    
    if (ac < 2)
    {
        write (1, "Options: \n-Julia \n-Mandelbort \n-Boats", 37);
        return (0);
    }
    ft_initialization(&fractol, ag, ac);
    if (fractol.fractal_type == -1)
    {
        write (1, "Options: \n-Julia \n-Mandelbort \n-Boats", 37);
        return (0);
    }
    write(1, "ok", 2);
}