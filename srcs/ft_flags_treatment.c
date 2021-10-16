#include "../includes/ft_printf.h"

t_flags	ft_star_treatment(t_flags *flags, va_list argptr)
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

t_flags	ft_digit_treatment(char c, t_flags *flags)
{
	if (flags->star)
		flags->width = 1;
	flags->width = (flags->width * 10) + (input[index] - '0');
	return (flags);
}

t_flags	ft_hyphen_treatment(t_flags *flags)
{
	flags->zero = 0;
	flags->hyphen = 1;
	return (flags);
}
