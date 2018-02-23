/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_or_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:35:10 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:35:11 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		space_zero(t_printf *print, const char *format, int d)
{
	int	i;
	int	nb_zero;

	i = 0;
	while (*format != '%')
	{
		--format;
		i++;
	}
	if (*++format == ' ' && *++format == '0')
	{
		ft_putchar(' ');
		++print->ret;
		while (*format == '0')
			++format;
		if (ft_isdigit(*format) == TRUE)
		{
			nb_zero = ft_atoi(format) - ft_strlen(ft_itoa(d)) - 1;
			while_nb_zero(nb_zero, print);
			ft_putnbr(d);
			print->ret += ft_strlen(ft_itoa(d));
			return (1);
		}
	}
	return (0);
}

void	put_space_or_zero(t_printf *print, int d)
{
	if (ft_strlen(ft_itoa(d)) > print->precision_zero)
	{
		print->precision_space -= ft_strlen(ft_itoa(d));
		print->space = 1;
	}
	else if (ft_strlen(ft_itoa(d)) < print->precision_zero)
	{
		if (d < 0)
			print->precision_space -= print->precision_zero + 1;
		else
			print->precision_space -= print->precision_zero;
		print->zero = 1;
	}
	if (d < 0)
		print->precision_zero -= ft_strlen(ft_itoa(d)) - 1;
	else
		print->precision_zero -= ft_strlen(ft_itoa(d));
	loop_space(print);
	if (d < 0)
		ft_putchar('-');
	while (print->precision_zero-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}
