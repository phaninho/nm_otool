/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:30:49 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:30:53 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	struct_is_zero(t_printf *print, const char *format)
{
	if (*format == '0')
		print->zero = 1;
}

void	decr_space_number(t_printf *print)
{
	if (print->negatif == 1)
		--print->space_number;
}

void	decr_precision_zero(t_printf *print, int z)
{
	if (z == 0)
		--print->precision_zero;
}
