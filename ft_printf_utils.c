/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristi <alcristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:52:22 by alcristi          #+#    #+#             */
/*   Updated: 2021/10/14 00:25:10 by alcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	printf_hex(void)
{
	write(1, "0x", 2);
	return (2);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_putnbr_base(unsigned long int nbr, char *base, char c)
{
	unsigned int	size;
	int				count;

	count = 0;
	size = ft_strlen(base);
	if (size <= 1 || check_base(base))
		return (0);
	if ((long)nbr < 0 && c != 'p')
	{
		count += ft_putchar_fd('-', 1);
		count += ft_putnbr_base(-nbr, base, c);
		return (count);
	}
	if (nbr >= size)
	{
		count += ft_putnbr_base(nbr / size, base, c);
		count += ft_putnbr_base(nbr % size, base, c);
	}
	else
	{
		count += ft_putchar_fd(base[nbr], 1);
	}
	return (count);
}
