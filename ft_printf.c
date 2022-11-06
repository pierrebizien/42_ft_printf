#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	ft_is_param(char c)
{
	int		i;
	char	param[] = "cspdiuxX%";

	i = 0;
	while (param[i])
	{
		if (param[i] == c)
			return(1);
		i++;
	}
	return (0);
}

int	ft_choice(char c, va_list ap)
{
	if(c == 'c')
		return (ft_putchar_ret((char)va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr_ret(va_arg(ap, char*)));
	else if (c == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_ret(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putnbr_u_ret(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_print_hexa_ret(va_arg(ap, unsigned int), 0));
	else if (c == 'X')
		return (ft_print_hexa_ret(va_arg(ap, unsigned int), 1));
	else 
		return (ft_putchar_ret(c));
	return (0);

}

int	ft_printf(const char *arg, ...)
{
	va_list ap;
	int 	count;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, arg);
	while (arg[i])
	{
		if (arg[i] == '%' && arg[i + 1])
		{
			i++;
			count += ft_choice(arg[i], ap);
		}
		else
		{
			write(1, &arg[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

// int main(int ac, char **argv)
// {
// 	int	a;
// 	int b;

// 	b = 2;
// 	a = ft_printf("%x", LONG_MAX);
// 	printf("\n%d",a);
// 	printf("\n");
// 	a = printf("%x", LONG_MAX);
// 	printf("\n%d",a);
// 	(void)ac;
// 	(void)argv;
// 	return (0);
	
// }
