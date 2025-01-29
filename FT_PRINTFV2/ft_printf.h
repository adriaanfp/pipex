/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflores- <aflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:34:57 by aflores-          #+#    #+#             */
/*   Updated: 2024/10/22 19:02:53 by aflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int			ft_putchar(char c);
int			ft_printstr(char *str);
int			ft_printint(int n);
int			ft_printunsigned(unsigned int u);
int			print_hexadecimal(unsigned int n, const char wrd);
int			ft_print_pointer(unsigned long long ptr);
int			ft_printf(char const *format, ...);

#endif
