/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:20:39 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/14 21:40:38 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int		hyphen;
	int		plus;
	int		space;
	int		sharp;
	int		zero;
	int		dot;
	int		star;
	int		width;
	char	type;
}				t_flags;

int		ft_type_is_valid(char c);
int		ft_putchar(char c);
int		ft_printf_split_by_args(char c, t_flags flags, va_list argptr);
int		ft_dot_treatment(const char *input, int i, t_flags *flags, \
va_list argptr);
int		ft_width_treatment(int width, int hyphen, int has_zero);
t_flags	ft_star_treatment(t_flags *flags, va_list argptr);
t_flags	ft_digit_treatment(char c, t_flags *flags);
t_flags	ft_hyphen_treatment(t_flags *flags);
int		ft_char_treatment(char c, t_flags flags);
int		ft_string_treatment(char *str, t_flags flags);

#endif
