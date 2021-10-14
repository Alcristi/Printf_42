/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristi <alcristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:52:26 by alcristi          #+#    #+#             */
/*   Updated: 2021/10/14 00:24:16 by alcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<stdlib.h>
# include<unistd.h>

int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
int		printf_hex(void);
int		check_base(char *base);
int		ft_putnbr_base(unsigned long int nbr, char *base, char c);
int		ft_printf(const char *src, ...);

#endif
