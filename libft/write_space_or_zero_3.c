/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_space_or_zero_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:35:49 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:35:51 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	loop_zero_no_ret(t_printf *print)
{
	print->ret += print->space_number;
	while (print->space_number-- > 0)
		ft_putchar('0');
}
