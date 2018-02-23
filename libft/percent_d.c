/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:32:41 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:32:42 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int			percent_d_1(t_printf *print, int z, int d)
{
	z = 0;
	if (d < 0 && print->point == 1)
		--print->space_number;
	if (print->space_number > print->precision_zero)
		z = 1;
	if (print->space_number > 0)
		print->neg_sign = 1;
	if (d < 0 && print->plus == 1)
		print->precision_zero--;
	if (print->space_number > 0 && print->precision_zero > 0 &&
			print->negatif == 0)
	{
		print->space_number -= print->precision_zero;
		if (print->plus == 1)
			--print->space_number;
		while (print->space_number-- > 0)
		{
			ft_putchar(' ');
			++print->ret;
		}
	}
	return (z);
}

static void			percent_d_2(t_printf *print, int z, int d)
{
	if (print->plus == 1 && print->precision_zero > 0 && d > 0)
	{
		ft_putchar('+');
		decr_space_number(print);
		decr_precision_zero(print, z);
		++print->ret;
	}
}

static int			percent_d_3(t_printf *print, int dd, int d)
{
	if (print->precision_zero > 0 || print->precision_space > 0)
	{
		put_space_or_zero(print, d);
		if (dd == 1 && print->point == 1)
			ft_putchar(' ');
		else if (d < 0)
			ft_putnbr(d * -1);
		else
			ft_putnbr(d);
		if (print->negatif == 1)
		{
			print->space_number -= (ft_strlen(ft_itoa(d))
					- print->precision_zero);
			while_space_number(print);
		}
		print->ret += ft_strlen(ft_itoa(d));
		return (1);
	}
	return (0);
}

static const char	*percent_d_4(const char *f, t_printf *print, int d)
{
	if (print->plus == 0 && print->point != 1)
		write_space_int(d, print);
	if (print->point == 1)
		f = precision(f, d, print);
	if (d >= 0 && print->plus == 0)
		while_space(print);
	if (print->plus == 1 && d >= 0)
	{
		ft_putchar('+');
		++print->ret;
	}
	while (*f != '%')
	{
		--f;
		print->i++;
	}
	return (f);
}

const char			*percent_d(va_list pa, t_printf *print, const char *format)
{
	int	d;
	int	z;
	int	dd;

	d = va_arg(pa, int);
	dd = print->d;
	print->d = d;
	print->neg_sign = 0;
	z = 0;
	z = percent_d_1(print, z, d);
	percent_d_2(print, z, d);
	if (percent_d_3(print, dd, d) == 1)
		return (format);
	if (space_zero(print, format, d) == 1)
		return (format);
	format = percent_d_4(format, print, d);
	format = percent_d_5(format, print, d);
	format += (print->i - 1);
	print->i = 0;
	write_space_int(d, print);
	if (print->point == 0)
		print->ret += ft_strlen(ft_itoa(d));
	return (format);
}
