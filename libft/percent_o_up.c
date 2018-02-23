/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_o_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:33:46 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:33:48 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	percent_o_up(va_list pa, t_printf *print)
{
	long	o;

	o = va_arg(pa, long);
	if (print->precision_zero > 0 || print->precision_space > 0)
		put_space_or_zero_o(print, o);
	if (print->sharp == 1 && o != 0)
	{
		ft_putchar('0');
		++print->ret;
	}
	if (o == -9223372036854775807 - 1)
	{
		ft_putstr("1000000000000000000000");
		print->ret += 22;
	}
	else
	{
		ft_putstr(ft_ltoa_base(o, 8));
		print->ret += ft_strlen(ft_ltoa_base(o, 8));
	}
}
