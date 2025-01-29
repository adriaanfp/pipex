/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflores- <aflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:39:55 by aflores-          #+#    #+#             */
/*   Updated: 2024/10/22 19:01:49 by aflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lenght_hexadecimal(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	search_hexadecimal(unsigned int n, const char wrd)
{
	if (n >= 16)
	{
		search_hexadecimal(n / 16, wrd);
		search_hexadecimal(n % 16, wrd);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
		{
			if (wrd == 'x')
				ft_putchar(n - 10 + 'a');
			else if (wrd == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
}

int	print_hexadecimal(unsigned int n, const char wrd)
{
	if (n == 0)
		return (ft_putchar('0'));
	else
		search_hexadecimal(n, wrd);
	return (lenght_hexadecimal(n));
}
