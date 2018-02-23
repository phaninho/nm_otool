/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_d_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:32:52 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:32:54 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static const char	*percent_d_up_1(va_list pa, t_printf *print, char const *f)
{
	unsigned int	u;

	u = va_arg(pa, unsigned int);
	if (print->space_number > ft_strlen(ft_ltoa(u)))
		print->space_number -= ft_strlen(ft_ltoa(u));
	if (print->zero == 1)
	{
		while (print->space_number-- > 0)
		{
			ft_putchar('0');
			++print->ret;
		}
	}
	if (print->precision_zero > 0 || print->precision_space > 0)
		put_space_or_zero_u(print, u);
	ft_put_long(u);
	print->ret += ft_strlen(ft_ltoa(u));
	while (print->space_number-- > 0 && print->point == 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
	return (f);
}

const char			*percent_d_up(va_list pa, t_printf *print, char const *f)
{
	long	d;

	d = 0;
	if (*f == 'D')
	{
		d = va_arg(pa, long);
		ft_put_long(d);
		print->ret += ft_strlen(ft_ltoa(d));
		return (f);
	}
	else if (*f == 'u')
		percent_d_up_1(pa, print, f);
	return (f);
}
