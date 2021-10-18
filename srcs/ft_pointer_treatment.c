/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_treatment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:16:04 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:43:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

#include "../includes/ft_printf.h"

int	ft_put_addr(char *ptr, t_flags flags)
{
	int	index;

	index = 0;
	index += ft_putstr("0x", 2);
	if (flags.dot > 0)
	{
		index += ft_width_treatment(flags.width, ft_strlen(ptr), 1);
		index += ft_putstr(ptr, flags.dot);
	}
	else
		index += ft_putstr(ptr, ft_strlen(ptr));
	return (index);
}

int	ft_pointer_treatment(unsigned long long addr, t_flags flags)
{
	char	*ptr;
	int		index;

	index = 0;
	if (addr == 0 && flags.dot == 0)
	{
		index += ft_putstr("0x", 2);
		index += ft_width_treatment(flags.width, 0, 1);
		return (index);
	}
	ptr = ft_convert_to_base(addr, 16);
	ptr = ft_tolower_str(ptr);
	if ((size_t)flags.dot < ft_strlen(ptr))
		flags.dot = ft_strlen(ptr);
	if (flags.hyphen == 1)
		index += ft_put_addr(ptr, flags);
	index += ft_width_treatment(flags.width, ft_strlen(ptr) + 2, 1);
	if (flags.hyphen == 0)
		index += ft_put_addr(ptr, flags);
	free(ptr);
	return (index);
}
