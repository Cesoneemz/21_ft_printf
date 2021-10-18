/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:45:42 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:43:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "../includes/ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.hyphen = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.sharp = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.star = 0;
	flags.width = 0;
	flags.type = ' ';
	return (flags);
}

int	ft_parse_flags(const char *input, int i, t_flags *flags, va_list argptr)
{
	while (input[i] != '\0')
	{
		if (input[i] == '0' && flags->width == 0 && flags->hyphen == 0)
			flags->zero = 1;
		if (input[i] == '-')
			flags = ft_hyphen_treatment(flags);
		if (input[i] == '+')
			flags->plus = 1;
		if (input[i] == '#')
			flags->sharp = 1;
		if (input[i] == '.')
			i = ft_dot_treatment(input, i, flags, argptr);
		if (input[i] == '*')
			flags = ft_star_treatment(flags, argptr);
		if (ft_isdigit(input[i]))
			flags = ft_digit_treatment(input[i], flags);
		if (ft_type_is_valid(input[i]))
		{
			flags->type = input[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_printf_parse(const char *input, va_list argptr)
{
	size_t	index;
	int		counter;
	t_flags	flags;

	counter = 0;
	index = 0;
	while (input[index] != '\0')
	{
		flags = ft_init_flags();
		if (input[index] == '%' && input[index])
		{
			index = ft_parse_flags(input, ++index, &flags, argptr);
			if (ft_type_is_valid(input[index]))
				counter += ft_printf_split_by_args(input[index], flags, argptr);
			else if (input[index])
				counter += ft_putchar(input[index]);
		}
		else if (input[index] != '%')
			counter += ft_putchar(input[index]);
		index++;
	}
	return (counter);
}

int	ft_printf(const char *input, ...)
{
	va_list	argptr;
	int		counter;

	counter = 0;
	va_start(argptr, input);
	counter += ft_printf_parse(input, argptr);
	va_end(argptr);
	return (counter);
}
