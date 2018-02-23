/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_space_or_zero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:35:36 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:35:37 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	loop_zero(t_printf *print)
{
	while (print->precision_zero-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	while_nb_zero(int nb_zero, t_printf *print)
{
	while (nb_zero-- > 0)
	{
		ft_putchar('0');
		++print->ret;
	}
}

void	loop_space(t_printf *print)
{
	while (print->precision_space-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
}

void	while_space_number(t_printf *print)
{
	while (print->space_number-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
}

void	while_space(t_printf *print)
{
	while (print->space-- > 0)
	{
		ft_putchar(' ');
		++print->ret;
	}
}
