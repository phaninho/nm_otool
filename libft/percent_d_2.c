/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_d_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:32:46 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:32:48 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

const char	*percent_d_5(const char *f, t_printf *print, int d)
{
	if (d < 0 && *++f == '0')
	{
		if (print->zero == 1 && print->neg_sign == 0)
			ft_putchar('-');
		ft_putnbr(d * -1);
		print->zero = 1;
	}
	else if (print->point == 0)
		ft_putnbr(d);
	else if (print->point == 1 && d > 0)
	{
		ft_putnbr(d);
		print->ret += ft_strlen(ft_itoa(d));
	}
	return (f);
}
