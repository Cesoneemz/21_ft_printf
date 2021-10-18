/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:45:42 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:43:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_char_treatment(char c, t_flags flags)
{
	int	index;

	if (flags.hyphen == 1)
		ft_putchar(c);
	index = ft_width_treatment(flags.width, 1, 0);
	if (flags.hyphen == 0)
		ft_putchar(c);
	return (index + 1);
}
