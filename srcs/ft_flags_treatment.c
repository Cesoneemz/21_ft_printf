/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_treatment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:45:42 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:43:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags	*ft_star_treatment(t_flags *flags, va_list argptr)
{
	flags->star = 1;
	flags->width = va_arg(argptr, int);
	if (flags->width < 0)
	{
		flags->hyphen = 1;
		flags->width *= -1;
	}
	return (flags);
}

t_flags	*ft_digit_treatment(char c, t_flags *flags)
{
	if (flags->star)
		flags->width = 1;
	flags->width = (flags->width * 10) + (c - '0');
	return (flags);
}

t_flags	*ft_hyphen_treatment(t_flags *flags)
{
	flags->zero = 0;
	flags->hyphen = 1;
	return (flags);
}
