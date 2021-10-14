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

int	ft_printf_split_by_args(char c, va_list argptr)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar(c);
	return (counter);
}
