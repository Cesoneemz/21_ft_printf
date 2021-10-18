/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_treatment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:45:42 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:43:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_put_int_part(char *str, t_flags flags)
{
	size_t	index;

	index = 0;
	if (flags.dot >= 0)
	{
		index += ft_width_treatment(flags.dot, ft_strlen(str), 0);
		index += ft_putstr(str, flags.dot);
	}
	else
	{
		index += ft_putstr(str, ft_strlen(str));
	}
	return (index);
}

int	ft_string_treatment(char *str, t_flags flags)
{
	size_t	index;

	index = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.hyphen == 1)
		index += ft_put_int_part(str, flags);
	if (flags.dot >= 0)
		index += ft_width_treatment(flags.width, flags.dot, 0);
	else
		index += ft_width_treatment(flags.width, ft_strlen(str), 0);
	if (flags.hyphen == 0)
		index += ft_put_int_part(str, flags);
	return (index);
}
