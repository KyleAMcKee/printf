#include "ft_printf.h"

void	print_max(intmax_t num)
{
	if (num < -9223372036854775807)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	if (num < 0)
		num *= -1;
	if (num >= 10)
	{
		print_max(num / 10);
		print_max(num % 10);
	}
	else
		ft_putchar(num + '0');
}
