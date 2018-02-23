/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:34:51 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:34:52 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static const char	*percent_z_1(va_list pa, t_printf *print, const char *f)
{
	unsigned long	z;

	if (*++f == 'd' || *f == 'i')
	{
		z = va_arg(pa, size_t);
		ft_put_long(z);
		print->ret += ft_strlen(ft_ltoa(z));
		return (f);
	}
	else if (*f == 'u' || *f == 'D')
	{
		z = va_arg(pa, size_t);
		ft_put_ulong(z);
		print->ret += ft_size_ttoa(z);
		return (f);
	}
	else if (*f == 'o')
	{
		z = va_arg(pa, size_t);
		ft_putstr(ft_ultoa_base(z, 8));
		print->ret += ft_strlen(ft_ultoa_base(z, 8));
		return (f);
	}
	return (f);
}

static const char	*percent_z_2(va_list pa, t_printf *print, const char *f)
{
	unsigned long	z;

	if (*f == 'x' || *f == 'X')
	{
		z = va_arg(pa, size_t);
		if (*f == 'x')
			ft_putstr(ft_hexa_ltoa(z, 0));
		else if (*f == 'X')
			ft_putstr(ft_hexa_ltoa(z, 1));
		print->ret += ft_strlen(ft_hexa_ltoa(z, 0));
		return (f);
	}
	else if (*f == 'O')
	{
		z = va_arg(pa, size_t);
		ft_putstr(ft_ultoa_base(z, 8));
		print->ret += ft_strlen(ft_ltoa_base(z, 8));
		return (f);
	}
	return (f);
}

const char			*percent_z(va_list pa, t_printf *print, const char *format)
{
	unsigned long	z;

	format = percent_z_1(pa, print, format);
	format = percent_z_2(pa, print, format);
	if (*format == 'U')
	{
		z = va_arg(pa, size_t);
		ft_putstr(ft_ultoa(z));
		print->ret += ft_strlen(ft_ultoa(z));
		return (format);
	}
	return (format);
}
