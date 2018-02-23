/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:32:20 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:32:21 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

const char	*percent_c(va_list pa, t_printf *print, const char *format)
{
	char	c;
	int		i;

	i = 0;
	c = va_arg(pa, int);
	while (*format != '%')
	{
		--format;
		i++;
	}
	++format;
	if (ft_isdigit(*format) == TRUE)
		put_space_or_zero(print, 1);
	format += i - 1;
	write_space_int(1, print);
	ft_putchar(c);
	write_space_int(1, print);
	++print->ret;
	return (format);
}
