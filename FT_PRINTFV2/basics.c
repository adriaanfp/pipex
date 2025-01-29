/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflores- <aflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:53:40 by aflores-          #+#    #+#             */
/*   Updated: 2024/10/22 19:00:14 by aflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		ft_putchar(*str);
		count++;
		str++;
	}
	return (count);
}

int	ft_printint(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n / 10)
		ft_printint(n / 10);
	ft_putchar(n % 10 + '0');
	return (n);
}

int	ft_printunsigned(unsigned int u)
{
	if (u >= 10)
		ft_printunsigned(u / 10);
	ft_putchar((u % 10) + '0');
	return (u);
}
