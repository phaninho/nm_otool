/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_j.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:33:05 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:33:06 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static const char	*percent_j_4(va_list pa, t_printf *print, const char *f)
{
	unsigned long	l;

	if (*f == 'x' || *f == 'X')
	{
		l = va_arg(pa, unsigned long);
		if (*f == 'x')
			ft_putstr(ft_hexa_ltoa(l, 0));
		else if (*f == 'X')
			ft_putstr(ft_hexa_ltoa(l, 1));
		print->ret += ft_strlen(ft_hexa_ltoa(l, 0));
		return (f);
	}
	else if (*f == 'U')
	{
		l = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa(l));
		print->ret += ft_strlen(ft_ultoa(l));
		return (f);
	}
	return (f);
}

static const char	*percent_j_3(va_list pa, t_printf *print, const char *f)
{
	unsigned long	l;

	if (*f == 'u')
	{
		l = va_arg(pa, unsigned long);
		ft_put_ulong(l);
		print->ret += ft_strlen(ft_ultoa(l));
		return (f);
	}
	else if (*f == 'o')
	{
		l = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa_base(l, 8));
		print->ret += ft_strlen(ft_ultoa_base(l, 8));
		return (f);
	}
	else if (*f == 'O')
	{
		l = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa_base(l, 8));
		print->ret += ft_strlen(ft_ltoa_base(l, 8));
		return (f);
	}
	return (f);
}

static const char	*percent_j_2(va_list pa, t_printf *print, const char *f)
{
	long			ld;
	unsigned long	l;

	if (*f == 'd' || *f == 'i')
	{
		ld = va_arg(pa, long);
		ft_put_long(ld);
		print->ret += ft_strlen(ft_ltoa(ld));
		return (f);
	}
	else if (*f == 'D')
	{
		l = va_arg(pa, unsigned long);
		ft_put_ulong(l);
		print->ret += ft_strlen(ft_ltoa(l));
		return (f);
	}
	return (f);
}

static const char	*percent_j_1(va_list pa, t_printf *print, const char *f)
{
	unsigned long	l;
	long long int	lld;

	if ((*++f == 'j') && (*++f == 'd' || *f == 'i'))
	{
		lld = va_arg(pa, long long int);
		ft_put_long(lld);
		print->ret += ft_strlen(ft_ltoa(lld));
		return (f);
	}
	else if ((*f == 'j') && *++f == 'u')
	{
		l = va_arg(pa, unsigned long);
		ft_put_ulong(l);
		print->ret += ft_strlen(ft_ultoa(l));
		return (f);
	}
	return (f);
}

const char			*percent_j(va_list pa, t_printf *print, const char *format)
{
	if ((*++format == 'j') && (*++format == 'd' || *format == 'i'))
		percent_j_1(pa, print, format);
	else if (*format == 'd' || *format == 'i' || *format == 'D')
		percent_j_2(pa, print, format);
	else if (*format == 'u' || *format == 'o' || *format == 'O')
		percent_j_3(pa, print, format);
	else if (*format == 'x' || *format == 'X' || *format == 'U')
		percent_j_4(pa, print, format);
	return (format);
}
