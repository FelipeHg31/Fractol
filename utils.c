/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:08:45 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/22 15:26:20 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void ft_tolower(char **str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		if (((*str)[i] >= 'A' && (*str)[i] <= 'Z'))
			(*str)[i] += 32;
		i++;
	}
}

int ft_strcmp(char *str1, char *str2)
{
	int i;
	
	i = 0;
	ft_tolower(&str1);
	while (str1[i] && str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] != str2[i])
		return (0);
	return (1);    
}

double ft_atof(char *str)
{
	double	result;
	double	fraction;
	int		divisor;
	int		sign;
	int		i;
	
	result = 0;
	fraction = 0;
	divisor = 1;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
	{
        i++;
        while (str[i] >= '0' && str[i] <= '9') {
            fraction = fraction * 10 + (str[i] - '0');
            divisor *= 10;
            i++;
        }
    }
	result += fraction / divisor;
	return (result * sign);
}