/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:33:53 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:33:54 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static const char	*percent_p_1(t_printf *print, char const *format)
{
	if (print->precision_zero <= 0 || print->precision_space <= 0)
	{
		if (*--format == '0')
		{
			ft_putstr("0x");
			print->ret += 2;
			print->ok = 2;
			return (format);
		}
		else
			++format;
	}
	while (*format != '%')
		--format;
	++format;
	if (*format == '0')
	{
		ft_putstr("0x");
		print->ok = 1;
	}
	return (format);
}

void				percent_p(va_list pa, t_printf *print, const char *format)
{
	char	*p;

	p = va_arg(pa, char*);
	format = percent_p_1(print, format);
	if (print->ok == 2)
		return ;
	format = take_precision(format, print);
	if (*format != '0' && *format != '-')
	{
		if (*format == '0')
			ft_putstr("0x");
		write_space_char(p, print);
	}
	if (*format != '0' && print->ok == 0)
		ft_putstr("0x");
	if (print->precision_zero > 0)
	{
		print->precision_zero -= ft_strlen(ft_hexa_ltoa((unsigned long)p, 0));
		loop_zero(print);
	}
	if (*format == '-')
		loop_space_no_ret(print);
	ft_putstr(ft_hexa_ltoa((unsigned long long)p, 0));
	write_space_char(p, print);
	print->ret += ft_strlen(ft_hexa_ltoa((unsigned long long)p, 0)) + 2;
}
