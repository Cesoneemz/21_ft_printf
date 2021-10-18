/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:54:43 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:55:31 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../includes/ft_printf.h"

int	ft_put_uint_proceed(char *buffer, t_flags flags)
{
	int	index;

	index = 0;
	if (flags.dot >= 0)
		index += ft_width_treatment(flags.dot, ft_strlen(buffer) - 1, 1);
	index += ft_putstr(buffer, ft_strlen(buffer));
	return (index);
}

int	ft_put_uint(char *buffer, t_flags flags)
{
	int	index;

	index = 0;
	if (flags.hyphen)
		index += ft_put_uint_proceed(buffer, flags);
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
		index += ft_put_uint_proceed(buffer, flags);
	return (index);
}

int	ft_uint_treatment(unsigned int nbr, t_flags flags)
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
	buffer = ft_uint_itoa(nbr);
	index += ft_put_uint(buffer, flags);
	free(buffer);
	return (index);
}
