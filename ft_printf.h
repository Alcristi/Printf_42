#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int	ft_putstr_fd(char *s, int fd);
int	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
int	printf_hex();
int	check_base (char *base);
int	ft_putnbr_base(unsigned long int nbr, char *base,char c);
int	ft_printf(const char* src, ...);

#endif
