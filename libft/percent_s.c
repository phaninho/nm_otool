/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:34:10 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:34:12 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	percent_s_1(t_printf *print, char *s, int space)
{
	if (print->zero == 1)
	{
		print->space_number -= space;
		while_space_number_zero(print);
	}
	if (print->precision_zero == 0 && print->precision_space > 0)
	{
		if (s != '\0' && print->point == 0)
			print->precision_space -= space;
		loop_space(print);
		if (s != '\0' && print->point == 0)
		{
			print->i = 1;
			ft_putstr(s);
			print->ret += space;
		}
		return (1);
	}
	return (0);
}

static void	percent_s_2(t_printf *print, int space, char *s)
{
	if (print->precision_space > print->precision_zero)
	{
		if (ft_strlen(s) < print->precision_zero)
			print->precision_space -= ft_strlen(s);
		else
			print->precision_space -= print->precision_zero;
		loop_space(print);
	}
	else if (print->precision_space < print->precision_zero &&
			print->negatif == 0)
	{
		print->precision_space -= space;
		loop_space(print);
	}
	else if (print->precision_zero > 0)
	{
		if (print->precision_zero < space)
			print->precision_space -= print->precision_zero;
		else if (print->precision_zero > space)
			print->precision_space -= space;
	}
	if (print->precision_space > 0)
		write_space_percent_s(space, print);
}

static void	percent_s_3(t_printf *print, char *s, int i, int nb_zero)
{
	if (print->precision_zero > 0 && ft_strlen(s) > print->precision_zero)
		while (print->precision_zero != 0)
		{
			ft_putchar(s[i++]);
			print->precision_zero--;
			++print->ret;
		}
	else
	{
		ft_putstr(s);
		print->ret += ft_strlen(s);
		if (print->negatif == 1)
		{
			print->space_number -= ft_strlen(s);
			while_space_number(print);
		}
	}
	if (print->space_number > 0)
	{
		print->space_number -= nb_zero;
		while_space_number(print);
	}
	if (print->precision_space > 0)
		write_space_percent_s(ft_strlen(s), print);
}

void		percent_s(va_list pa, t_printf *print)
{
	char	*s;
	int		nb_zero;
	int		i;

	i = 0;
	s = va_arg(pa, char*);
	nb_zero = print->precision_zero;
	if (s == '\0')
		print->space_number > 0 ? while_space_number_zero(print)
			: write_null(print);
	else
	{
		if (percent_s_1(print, s, ft_strlen(s)) == 1)
			return ;
		percent_s_2(print, ft_strlen(s), s);
		percent_s_3(print, s, i, nb_zero);
	}
}
