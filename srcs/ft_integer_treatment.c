/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_treatment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:03:51 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:43:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdlib.h>

int	ft_put_int(char *buffer, int nbr, t_flags flags)
{
	int	index;

	index = 0;
	if (nbr < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		index += ft_width_treatment(flags.dot - 1, ft_strlen(buffer), 1);
	index += ft_putstr(buffer, ft_strlen(buffer));
	return (index);
}

int	ft_put_nbr(char *buffer, int nbr, t_flags flags)
{
	int	index;

	index = 0;
	if (flags.hyphen == 1)
		index += ft_put_int(buffer, nbr, flags);
	if (flags.dot >= 0 && (size_t)flags.dot <= ft_strlen(buffer))
		flags.dot = ft_strlen(buffer);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		index += ft_width_treatment(flags.width, 0, 0);
	}
	else
		index += ft_width_treatment(flags.width, ft_strlen(buffer), flags.zero);
	if (flags.hyphen == 0)
		index += ft_put_int(buffer, nbr, flags);
	return (index);
}

int	ft_integer_treatment(int nbr, t_flags flags)
{
	int		save;
	int		index;
	char	*buffer;

	save = nbr;
	index = 0;
	if (flags.dot == 0 && nbr == 0)
	{
		index += ft_width_treatment(flags.width, 0, 0);
		return (index);
	}
	if (nbr < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			ft_putstr("-", 1);
		nbr *= -1;
		flags.zero = 1;
		flags.width--;
		index++;
	}
	buffer = ft_itoa(nbr);
	index += ft_put_nbr(buffer, save, flags);
	free(buffer);
	return (index);
}
