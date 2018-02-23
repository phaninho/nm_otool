/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_l_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:33:29 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:33:31 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	percent_l_6(va_list pa, t_printf *print, const char *f)
{
	unsigned long int	ull;

	if (*f == 'o')
	{
		ull = va_arg(pa, unsigned long long int);
		ft_putstr(ft_ultoa_base(ull, 8));
		print->ret += ft_strlen(ft_ultoa_base(ull, 8));
	}
	else if (*f == 'x' || *f == 'X')
	{
		if (print->sharp == 1)
		{
			ft_putstr("0x");
			print->ret += 2;
		}
		ull = va_arg(pa, unsigned long long int);
		if (*f == 'x')
			ft_putstr(ft_hexa_ltoa(ull, 0));
		else if (*f == 'X')
			ft_putstr(ft_hexa_ltoa(ull, 1));
		print->ret += ft_strlen(ft_hexa_ltoa(ull, 0));
	}
}

void	percent_l_5(va_list pa, t_printf *print, const char *f)
{
	unsigned long int	ull;
	long long int		lld;

	if (*f == 'd' || *f == 'i')
	{
		lld = va_arg(pa, long long int);
		ft_put_long(lld);
		print->ret += ft_strlen(ft_ltoa(lld));
	}
	else if (*f == 'u')
	{
		ull = va_arg(pa, unsigned long long int);
		ft_put_ulong(ull);
		print->ret += ft_strlen(ft_ultoa(ull));
	}
}
