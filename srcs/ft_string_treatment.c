#include "../includes/ft_printf.h"

int	ft_putstr(char *str, int prec)
{
	int	index;

	index = 0;
	while (str[index] && index < prec)
		ft_putchar(str[index++]);
	return (index);
}

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
