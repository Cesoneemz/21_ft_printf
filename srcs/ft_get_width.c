#include "../includes/ft_printf.h"

int	ft_width_treatment(int width, int hyphen, int has_zero)
{
	size_t	index;

	index = 0;
	while (width - hyphen > 0)
	{
		if (has_zero)
			ft_putchar(0);
		else
			ft_putchar(' ');
		width--;
		index++;
	}
	return (index);
}