/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:31:37 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:31:38 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	put_space_or_zero_u(t_printf *print, unsigned int d)
{
	if (ft_strlen(ft_ltoa(d)) > print->precision_zero)
	{
		print->precision_zero -= ft_strlen(ft_ltoa(d));
		print->precision_space -= ft_strlen(ft_ltoa(d));
		print->zero = 1;
	}
	else if (ft_strlen(ft_ltoa(d)) < print->precision_zero)
	{
		print->precision_zero -= ft_strlen(ft_ltoa(d));
		print->precision_space -= ft_strlen(ft_ltoa(d)) + print->precision_zero;
		print->zero = 1;
	}
	while (print->precision_space-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
	while (print->precision_zero-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	put_space_or_zero_o(t_printf *print, int d)
{
	if (ft_strlen(ft_ltoa(d)) > print->precision_zero)
	{
		print->precision_zero -= ft_strlen(ft_itoa_base(d, 8));
		print->precision_space -= ft_strlen(ft_itoa_base(d, 8));
		print->zero = 1;
	}
	else if (ft_strlen(ft_ltoa(d)) < print->precision_zero)
	{
		print->precision_zero -= ft_strlen(ft_itoa_base(d, 8));
		print->precision_space -= ft_strlen(ft_itoa_base(d, 8))
			+ print->precision_zero;
		print->zero = 1;
	}
	while (print->precision_space-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
	while (print->precision_zero-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	put_space_or_zero_x(t_printf *print, int x)
{
	if (ft_strlen(ft_ltoa(x)) > print->precision_zero)
	{
		print->precision_zero -= ft_strlen(ft_hexa_itoa(x, 0));
		print->precision_space -= ft_strlen(ft_hexa_itoa(x, 0));
		print->zero = 1;
	}
	else if (ft_strlen(ft_ltoa(x)) < print->precision_zero)
	{
		print->precision_zero -= ft_strlen(ft_hexa_itoa(x, 0));
		print->precision_space -= ft_strlen(ft_hexa_itoa(x, 0))
			+ print->precision_zero;
		print->zero = 1;
	}
	loop_space(print);
	if (print->sharp == 1)
	{
		ft_putstr("0x");
		print->ret += 2;
		print->sharp = 0;
	}
	while (print->precision_zero-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	put_space_or_zero_s(t_printf *print, char *s)
{
	if (ft_strlen(s) > print->precision_space)
	{
		print->precision_zero -= ft_strlen(s);
		print->precision_space -= ft_strlen(s);
		print->zero = 1;
	}
	while (print->precision_space-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
}
