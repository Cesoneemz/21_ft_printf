/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:48:12 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/14 21:40:25 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>

#include "../includes/ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.hyphen = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.sharp = 0;
	flags.zero = 0;
	flags.dot = 0;
	flags.width = 0;
	flags.type = ' ';
	return (flags);
}

int	ft_parse_flags(const char *input, t_flags *flags, va_list argptr)
{
	size_t	index;

	index = 0;
	while (input[index] != '\0')
	{
		if (input[index] == '0' && flags->width == 0 && flags->hyphen == 0)
			flags->zero = 0;
		if (input[index] == '-')
		if (input[index] == '+')
		if (input[index] == ' ')
		if (input[index] == '#')
		if (input[index] == '.')
		if (input[index] == '*')
		if (ft_isdigit(input[index]))
		if (ft_type_if_valid(input[index]))
		{
			flags->type = input[index];
			break ;
		}
		index++;
	}
	return (index);
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
		if (input[index] == '%' && input[index + 1])
		{
			if (ft_type_is_valid(input[index + 1]))
				counter += ft_printf_split_by_args(input[index + 1], argptr);	
			else if (input[index])
				counter += ft_putchar(input[index]);
		}
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

int	main(void)
{
	char	c;

	c = 'a';
	printf("%-10c\n", c);
}
