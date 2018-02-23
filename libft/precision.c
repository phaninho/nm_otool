/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:34:59 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:35:01 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

const char	*precision(const char *format, int d, t_printf *print)
{
	if (*format == 'd')
		return (format);
	++format;
	print->precision_zero -= ft_strlen(ft_itoa(d));
	if (print->precision_zero > 0)
		while (print->precision_zero--)
		{
			ft_putchar('0');
			++print->ret;
		}
	return (format);
}

const char	*take_precision(const char *format, t_printf *print)
{
	if (*format == '-')
		++format;
	if (ft_isdigit(*format) == TRUE)
		print->precision_space = ft_atoi(format);
	if (*++format == '%')
	{
		space_number_inf(print);
		return (format);
	}
	else
		--format;
	while (*format != '.')
	{
		if (ft_isalpha(*format) == TRUE)
			return (format);
		++format;
	}
	if (*format == '.')
		print->point = 1;
	++format;
	if (ft_isalpha(*format) == 1)
		return (format);
	print->precision_zero = ft_atoi(format);
	++format;
	return (format);
}
