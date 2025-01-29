/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflores- <aflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:37:45 by aflores-          #+#    #+#             */
/*   Updated: 2024/10/22 19:04:05 by aflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_pointer(unsigned long long ptr)
{
	int	length;

	length = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0)
	{
		ptr /= 16;
		length++;
	}
	return (length);
}

static void	search_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		search_pointer(ptr / 16);
		search_pointer(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	size;

	size = 0;
	size += ft_printstr("0x");
	if (ptr == 0)
		size += ft_putchar('0');
	else
	{
		search_pointer(ptr);
		size += ft_length_pointer(ptr);
	}
	return (size);
}
