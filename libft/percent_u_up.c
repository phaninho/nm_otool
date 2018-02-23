/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_u_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:34:34 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:34:36 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	percent_u_up(va_list pa, t_printf *print)
{
	unsigned long	u;

	u = va_arg(pa, unsigned long);
	ft_put_ulong(u);
	if (ft_strlen(ft_ultoa(u)) == 20)
		print->ret += 20;
	else
		print->ret += ft_strlen(ft_ultoa(u));
}
