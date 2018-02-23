/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_s_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:34:20 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:34:22 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		count_octet_wchar_1(t_printf *print, int octet)
{
	if (print->precision_space > 0)
		if (print->precision_space < octet)
		{
			++print->ret;
			print->precision_space -= 3;
			print->i = 1;
			return (octet);
		}
	octet += 3;
	return (octet);
}

int				count_octet_wchar(wchar_t *s, t_printf *print)
{
	int	i;
	int	octet;

	i = 0;
	octet = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			if (s[i] > 0 && s[i] < 128)
				octet++;
			else if (s[i] < 2048)
				octet += 2;
			else if (s[i] < 65536)
			{
				octet = count_octet_wchar_1(print, octet);
				if (print->i == 1)
					return (octet);
			}
			else if (s[i] < 1114112)
				octet += 4;
			i++;
		}
	}
	return (octet);
}

void			percent_s_up_normal(t_printf *print, wchar_t *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			percent_s_up_normal_1(print, s, i);
			i++;
		}
	}
	else
	{
		ft_putstr("(null)");
		print->ret += 6;
	}
	if (print->negatif == 1)
	{
		print->ret_wchar = count_octet_wchar(s, print);
		write_space_wchar(print);
		write_space_wchar(print);
	}
	print->ret += count_octet_wchar(s, print);
}

static void		percent_s_up_1(t_printf *print, wchar_t *s, int cp_pre_space)
{
	if (print->precision_space > 0 || print->precision_zero > 0)
	{
		if (print->precision_space > 0 && print->precision_zero > 0)
		{
			if (print->precision_space < print->precision_zero)
			{
			}
			else
			{
				print->precision_space -= count_octet_wchar(s, print);
				print->precision_space = cp_pre_space - 3;
				loop_space(print);
			}
			percent_s_up_precision(print, s);
		}
		else
		{
			print->precision_space -= count_octet_wchar(s, print);
			loop_space(print);
			percent_s_up_precision(print, s);
		}
	}
	else
		percent_s_up_normal(print, s);
}

void			percent_s_up(va_list pa, t_printf *print)
{
	wchar_t			*s;
	int				i;
	int				cp_pre_space;

	i = 0;
	if (print->precision_space > 0 && print->point == 1)
	{
		loop_space(print);
		return ;
	}
	cp_pre_space = print->precision_space;
	s = va_arg(pa, wchar_t*);
	if (print->space_number > 0 && print->precision_space == 0 &&
		print->negatif == 0 && print->point == 1)
	{
		loop_zero_no_ret(print);
		return ;
	}
	if (print->zero == 1)
	{
		print->space_number -= count_octet_wchar(s, print);
		while_precision_space(print);
		while_space_number_zero(print);
	}
	percent_s_up_1(print, s, cp_pre_space);
}
