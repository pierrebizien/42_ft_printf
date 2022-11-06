#include "ft_printf.h"
#include <limits.h>

void	ft_putnbr_u(unsigned int n, int *count)
{
	char		c;

	if (n >= 10)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else
	{
		c = n + '0';
		*count = *count + 1;
		write(1, &c, 1);
	}
}

int	ft_putnbr_u_ret(unsigned int n)
{
	int count;

	count = 0;
	ft_putnbr_u(n, &count);
	return (count);
}

void	ft_putnbr(int n, int *count)
{
	char		c;

	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		*count = *count + 11;
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_ret('-');
		*count = *count + 1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else
	{
		c = n + '0';
		*count = *count + 1;
		write(1, &c, 1);
	}
}

int	ft_putnbr_ret(int n)
{
	int count;

	count = 0;
	ft_putnbr(n, &count);
	return (count);
}