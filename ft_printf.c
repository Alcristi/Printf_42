#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
int	printf_number(va_list *ap, char c)
{
	int	count;

	count = 0;
	if (c == 'i' || c == 'd' )
		count += ft_putnbr_base(va_arg(*ap, int), "0123456789", c);
	else if (c == 'u')
		count += ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789", c);
	else if (c == 'p')
	{
		count += printf_hex();
		count += ft_putnbr_base((unsigned long int)va_arg(*ap, void *),
				"0123456789abcdef", c);
	}
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789abcdef",
				c);
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(*ap, unsigned int), "0123456789ABCDEF",
				c);
	return (count);
}

int	verific(va_list *ap, char c)
{
	int		count;
	char	*hex;

	count = 0;
	if (c == 'i' || c == 'd' || c == 'u' || c == 'p' || c == 'x' || c == 'X')
		count = printf_number(ap, c);
	else if (c == 'c')
		count += ft_putchar_fd(va_arg(*ap, int), 1);
	else if (c == 's')
		count += ft_putstr_fd(va_arg(*ap, char *), 1);
	else if (c == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *src, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(ap, src);
	while (src[i])
	{
		if (src[i] == '%')
			count += verific(&ap, src[++i]);
		else
			count += ft_putchar_fd(src[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
