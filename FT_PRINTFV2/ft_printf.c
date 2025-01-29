/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflores- <aflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:13:05 by aflores-          #+#    #+#             */
/*   Updated: 2024/10/22 19:05:08 by aflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list va, const char wrd)
{
	int	size;

	size = 0;
	if (wrd == 'c')
		size += ft_putchar(va_arg(va, int));
	else if (wrd == 's')
		size += ft_printstr(va_arg(va, char *));
	else if (wrd == 'p')
		size += ft_print_pointer(va_arg(va, unsigned long long));
	else if (wrd == 'd' || wrd == 'i')
		size += ft_printint(va_arg(va, int));
	else if (wrd == 'u')
		size += ft_printunsigned(va_arg(va, unsigned int));
	else if (wrd == 'x' || wrd == 'X')
		size += print_hexadecimal(va_arg(va, unsigned int), wrd);
	else if (wrd == '%')
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		size;
	int		i;

	size = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (*format == '%' && format[i + 1] != 0)
		{
			i++;
			size += ft_format(args, format[i]);
		}
		else
		{
			ft_putchar(format[i]);
			size++;
		}
		i++;
	}
	va_end(args);
	return (size);
}
