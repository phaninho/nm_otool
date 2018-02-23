/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:32:58 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:33:00 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static void	percent_h_1(va_list pa, t_printf *print, const char *format)
{
	short int			hdi;
	unsigned short int	h;

	if (*format == 'd' || *format == 'i')
	{
		hdi = va_arg(pa, int);
		ft_putnbr(hdi);
		print->ret += ft_strlen(ft_itoa(hdi));
	}
	else if (*format == 'u' || *format == 'D')
	{
		h = va_arg(pa, int);
		ft_putnbr(h);
		print->ret += ft_strlen(ft_itoa(h));
	}
	else if (*format == 'o')
	{
		h = va_arg(pa, int);
		ft_putstr(ft_ultoa_base(h, 8));
		print->ret += ft_strlen(ft_ultoa_base(h, 8));
	}
}

static void	percent_h_2(va_list pa, t_printf *print, const char *format)
{
	unsigned short int	h;
	unsigned long		hl;

	if (*format == 'x' || *format == 'X')
	{
		h = va_arg(pa, unsigned long);
		if (*format == 'x')
			ft_putstr(ft_hexa_ltoa(h, 0));
		else if (*format == 'X')
			ft_putstr(ft_hexa_ltoa(h, 1));
		print->ret += ft_strlen(ft_hexa_ltoa(h, 0));
	}
	else if (*format == 'O')
	{
		h = va_arg(pa, unsigned long);
		ft_putstr(ft_ultoa_base(h, 8));
		print->ret += ft_strlen(ft_ltoa_base(h, 8));
	}
	else if (*format == 'U')
	{
		hl = va_arg(pa, unsigned long);
		ft_put_ulong(hl);
		print->ret += ft_strlen(ft_ultoa(hl));
	}
}

static void	percent_h_3(va_list pa, t_printf *print, const char *format)
{
	unsigned char	hhu;

	if (*format == 'u')
	{
		hhu = va_arg(pa, int);
		ft_putnbr(hhu);
		print->ret += ft_strlen(ft_itoa(hhu));
	}
	else if (*format == 'o')
	{
		hhu = va_arg(pa, int);
		ft_putstr(ft_itoa_base(hhu, 8));
		print->ret += ft_strlen(ft_itoa_base(hhu, 8));
	}
	else if (*format == 'x' || *format == 'X')
	{
		hhu = va_arg(pa, int);
		if (*format == 'x')
			ft_putstr(ft_hexa_itoa(hhu, 0));
		else if (*format == 'X')
			ft_putstr(ft_hexa_ltoa(hhu, 1));
		print->ret += ft_strlen(ft_hexa_itoa(hhu, 0));
	}
}

static void	percent_h_4(va_list pa, t_printf *print, const char *format)
{
	if (*format == 'C')
		percent_c_up(pa, print);
	else if (*format == 'S')
		percent_s_up(pa, print);
}

const char	*percent_h(va_list pa, t_printf *print, const char *f)
{
	char	hh;

	if (*++f == 'h' && (*++f == 'd' || *f == 'i' || *f == 'u' || *f == 'o' ||
		*f == 'x' || *f == 'X' || *f == 'C' || *f == 'S'))
	{
		if (*f == 'u' || *f == 'o' || *f == 'x' || *f == 'X')
			percent_h_3(pa, print, f);
		else if (*f == 'C' || *f == 'S')
			percent_h_4(pa, print, f);
		else
		{
			hh = va_arg(pa, int);
			ft_putnbr(hh);
			print->ret += ft_strlen(ft_itoa(hh));
		}
	}
	else if (*f == 'u' || *f == 'd' || *f == 'D' || *f == 'i' || *f == 'o')
		percent_h_1(pa, print, f);
	else if (*f == 'x' || *f == 'X' || *f == 'O' || *f == 'U')
		percent_h_2(pa, print, f);
	return (f);
}
