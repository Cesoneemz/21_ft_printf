/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:45:42 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:55:34 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_split_by_args(char c, t_flags flags, va_list argptr)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_char_treatment(va_arg(argptr, int), flags);
	else if (c == 's')
		counter += ft_string_treatment(va_arg(argptr, char *), flags);
	else if (c == 'p')
		counter += ft_pointer_treatment(va_arg(argptr, unsigned long long), \
		flags);
	else if (c == 'd' || c == 'i')
		counter += ft_integer_treatment(va_arg(argptr, int), flags);
	else if (c == 'u')
		counter += ft_uint_treatment(\
		(unsigned int)va_arg(argptr, unsigned int), flags);
	else if (c == 'x' || c == 'X')
		counter += ft_hex_treatment(va_arg(argptr, unsigned int), flags);
	else if (c == '%')
		counter += ft_char_treatment('%', flags);
	return (counter);
}

int	ft_dot_treatment(const char *input, int i, t_flags *flags, va_list argptr)
{
	size_t	index;

	index = i + 1;
	if (input[index] == '*')
	{
		flags->dot = va_arg(argptr, int);
		index++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(input[index]))
		{
			flags->dot = (flags->dot * 10) + (input[index] - '0');
			index++;
		}
	}
	return ((int)index);
}

char	*ft_tolower_str(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		str[index] = ft_tolower(str[index]);
		index++;
	}
	return (str);
}
