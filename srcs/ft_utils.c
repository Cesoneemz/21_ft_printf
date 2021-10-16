/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:53:06 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/14 20:20:12 by wlanette         ###   ########.fr       */
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
