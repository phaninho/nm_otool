/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_space_or_zero_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:35:42 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:35:43 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	loop_space_no_ret(t_printf *print)
{
	while (print->precision_space-- > 0)
		ft_putchar(' ');
}

void	while_precision_space(t_printf *print)
{
	while (print->precision_space-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	while_space_number_zero(t_printf *print)
{
	while (print->space_number-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	write_null(t_printf *print)
{
	ft_putstr("(null)");
	print->ret += 6;
}

void	space_number_inf(t_printf *print)
{
	while (--print->precision_space > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
}
