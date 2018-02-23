/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:33:14 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:33:15 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static void	percent_l_4(va_list pa, t_printf *print, const char *f)
{
	if (*f == 's')
		percent_s_up(pa, print);
	else if (*f == 'p')
		percent_p(pa, print, f);
}

static void	percent_l_3(va_list pa, t_printf *print, const char *f)
{
	unsigned long int	l;

	if (*f == 'O')
	{
		l = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa_base(l, 8));
		print->ret += ft_strlen(ft_ltoa_base(l, 8));
	}
	else if (*f == 'U')
	{
		l = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa(l));
		print->ret += ft_strlen(ft_ultoa(l));
	}
	else if (*f == 'c')
		percent_c_up(pa, print);
}

static void	percent_l_2(va_list pa, t_printf *print, const char *f)
{
	unsigned long int	l;

	if (*f == 'o')
	{
		l = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa_base(l, 8));
		print->ret += ft_strlen(ft_ultoa_base(l, 8));
	}
	else if (*f == 'x' || *f == 'X')
	{
		l = va_arg(pa, unsigned long);
		if (*f == 'x')
			ft_putstr(ft_hexa_ltoa(l, 0));
		else if (*f == 'X')
			ft_putstr(ft_hexa_ltoa(l, 1));
		print->ret += ft_strlen(ft_hexa_ltoa(l, 0));
	}
}

static void	percent_l_1(va_list pa, t_printf *print, const char *f)
{
	long				ld;
	unsigned long int	l;

	if (*f == 'u')
	{
		l = va_arg(pa, unsigned long int);
		ft_put_ulong(l);
		print->ret += ft_strlen(ft_ultoa(l));
	}
	else if (*f == 'd' || *f == 'i')
	{
		ld = va_arg(pa, long);
		ft_put_long(ld);
		print->ret += ft_strlen(ft_ltoa(ld));
	}
	else if (*f == 'D')
	{
		l = va_arg(pa, unsigned long);
		ft_put_ulong(l);
		print->ret += ft_strlen(ft_ltoa(l));
	}
}

const char	*percent_l(va_list pa, t_printf *print, const char *format)
{
	if (*++format == 'l' && (*++format == 'd' || *format == 'i' ||
		*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X'))
	{
		if (*format == 'd' || *format == 'i' || *format == 'u')
			percent_l_5(pa, print, format);
		else if (*format == 'x' || *format == 'X' || *format == 'o')
			percent_l_6(pa, print, format);
		return (format);
	}
	if (*format == 'u' || *format == 'd' || *format == 'i' || *format == 'D')
		percent_l_1(pa, print, format);
	else if (*format == 'o' || *format == 'x' || *format == 'X')
		percent_l_2(pa, print, format);
	else if (*format == 'O' || *format == 'U' || *format == 'c')
		percent_l_3(pa, print, format);
	else if (*format == 's' || *format == 'p')
		percent_l_4(pa, print, format);
	else
		--format;
	return (format);
}
