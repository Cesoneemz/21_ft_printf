/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_treatment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:50:14 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:43:05 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../includes/ft_printf.h"

int	ft_put_hex_proceed(char *buffer, t_flags flags)
{
	int	index;

	index = 0;
	if (flags.dot >= 0)
		index += ft_width_treatment(flags.dot, ft_strlen(buffer) - 1, 1);
	index += ft_putstr(buffer, ft_strlen(buffer));
	return (index);
}

int	ft_put_hex(char *buffer, t_flags flags)
{
	int	index;

	index = 0;
	if (flags.hyphen)
		index += ft_put_hex_proceed(buffer, flags);
	if (flags.dot >= 0 && (size_t) flags.dot < ft_strlen(buffer))
		flags.dot = ft_strlen(buffer);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		index += ft_width_treatment(flags.width, 0, 0);
	}
	else
		index += ft_width_treatment(flags.width, ft_strlen(buffer), flags.zero);
	if (!flags.hyphen)
		index += ft_put_hex_proceed(buffer, flags);
	return (index);
}

int	ft_hex_treatment(unsigned int nbr, t_flags flags)
{
	int				index;
	char			*buffer;

	index = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	if (flags.dot == 0 && nbr == 0)
	{
		index += ft_width_treatment(flags.width, 0, 0);
		return (index);
	}
	buffer = ft_convert_to_base((unsigned long long)nbr, 16);
	if (flags.type == 'x')
		buffer = ft_tolower_str(buffer);
	index += ft_put_hex(buffer, flags);
	free(buffer);
	return (index);
}
