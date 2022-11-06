#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *arg, ...);
int	ft_putchar_ret(char c);
int	ft_putstr_ret(char *str);
int	ft_print_hexa(unsigned long a, int param_min_maj, int *count);
int ft_putptr(void *ptr);
void	ft_putnbr(int n, int *count);
int	ft_putnbr_ret(int n);
int	ft_putnbr_u_ret(unsigned int n);
void	ft_putnbr_u(unsigned int n, int *count);
int	ft_print_hexa_ret(unsigned int n, int param);

#endif