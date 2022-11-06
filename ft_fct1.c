#include "ft_printf.h"
#include <limits.h>

int	ft_putchar_ret(char c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_putstr_ret(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return(6);
	}
	while (str[i])
	{
		ft_putchar_ret(str[i]);
		i++;
	}
	return(i);
}

int	ft_print_hexa(unsigned long a, int param_min_maj, int *count)
{
	char		base_min[] = "0123456789abcdef";
	char		base_maj[] = "0123456789ABCDEF";

	if (a >= 16)
	{
		ft_print_hexa(a / 16, param_min_maj, count);
		ft_print_hexa(a % 16, param_min_maj, count);
	}
	else
	{
		*count = *count + 1;
		if (param_min_maj == 0)
			write(1, &base_min[a], 1);
		if (param_min_maj == 1)
			write(1, &base_maj[a], 1);
	}
	return (*count);
}

int ft_putptr(void *ptr)
{
	unsigned long	x;
	int	count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	x = (unsigned long)ptr;
	count = 2;
	write(1, "0x", 2);
	ft_print_hexa(x, 0, &count);
	return (count);
}

int	ft_print_hexa_ret(unsigned int n, int param)
{
	int count;

	count = 0;
	ft_print_hexa(n, param, &count);
	return (count);
}