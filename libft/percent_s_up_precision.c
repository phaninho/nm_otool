/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_s_up_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:34:28 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:34:29 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static void	percent_s_up_precision_1(t_printf *print, wchar_t *s, int z, int i)
{
	print->ret_wchar++;
	if (print->precision_zero > 0)
		if (print->ret_wchar > z)
		{
			++print->ret;
			print->i = 1;
			return ;
		}
	ft_putchar(s[i]);
}

static void	percent_s_up_precision_2(t_printf *print, wchar_t *s, int z, int i)
{
	print->ret_wchar += 2;
	if (print->precision_zero > 0)
		if (print->ret_wchar > z)
		{
			print->ret += 2;
			print->i = 1;
			return ;
		}
	ft_putchar(192 | (s[i] >> 6));
	ft_putchar(128 | (s[i] & 63));
}

static void	percent_s_up_precision_3(t_printf *print, wchar_t *s, int z, int i)
{
	print->ret_wchar += 3;
	if (print->precision_zero > 0)
		if (print->ret_wchar > z)
		{
			print->ret += 3;
			print->i = 1;
			return ;
		}
	ft_putchar(224 | (s[i] >> 12));
	ft_putchar(128 | ((s[i] >> 6) & 63));
	ft_putchar(128 | (s[i] & 63));
}

void		percent_s_up_precision(t_printf *print, wchar_t *s)
{
	int	i;
	int	zero_plus_wchar;

	i = 0;
	if (print->negatif == 0)
	{
		print->ret_wchar = count_octet_wchar(s, print);
		write_space_wchar(print);
	}
	zero_plus_wchar = print->precision_zero + print->ret_wchar;
	if (s != NULL)
		while (s[i])
		{
			if (s[i] > 0 && s[i] < 128)
				percent_s_up_precision_1(print, s, zero_plus_wchar, i);
			else if (s[i] < 2048)
				percent_s_up_precision_2(print, s, zero_plus_wchar, i);
			else if (s[i] < 65536)
				percent_s_up_precision_3(print, s, zero_plus_wchar, i);
			else if (s[i] < 1114112)
				percent_s_up_precision_3(print, s, zero_plus_wchar, i);
			i++;
		}
	print->ret += count_octet_wchar(s, print);
}
