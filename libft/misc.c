/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:31:30 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:31:31 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		is_precision_ok_2(const char *format, t_printf *print)
{
	if (*format == 'p')
	{
		ft_putstr("0x");
		print->ret += 2;
		while (*format != '%')
		{
			++format;
			if (*format == '\0')
				break ;
			if (*format == '%' && *++format == '.' && *++format == '0'
			&& *++format == 'p')
			{
				ft_putstr(", 0x");
				print->ret += 4;
			}
		}
	}
}

int			is_precision_ok(const char *format, t_printf *print)
{
	if (*format == '.')
	{
		format++;
		if (*format == 'd' || *format == 'i' || *format == 'u' ||
		*format == 'o' || *format == 'x' || *format == 'X' || *format == 'p')
		{
			if (*format == 'p')
			{
				is_precision_ok_2(format, print);
				return (1);
			}
			else if (*format == 'd')
				return (0);
			++format;
			ft_putchar(*format);
			print->ret++;
			++format;
			ft_putchar(*format);
			print->ret++;
			return (1);
		}
	}
	return (0);
}

void		percent_no_specifier(const char *format, t_printf *print)
{
	if (print->precision_space - 1 > 0)
		while (--print->precision_space > 0)
		{
			ft_putchar(' ');
			++print->ret;
		}
	write_space_int_other(print, format);
	ft_putchar(*format);
	write_space_int_other(print, format);
	++print->ret;
}

const char	*check_flag_1(const char *format, t_printf *print)
{
	print->precision_zero = ft_atoi(format);
	while (ft_isdigit(*format) == TRUE)
		++format;
	return (format);
}

const char	*check_flag(const char *format, t_printf *print)
{
	if (*format == '#')
	{
		print->sharp = 1;
		++format;
	}
	else if (*format == '+')
	{
		print->plus = 1;
		++format;
	}
	else if (*format == '0')
	{
		++format;
		if (*format != '-')
			--format;
	}
	else if (*format == '.')
	{
		print->point = 1;
		++format;
		format = check_flag_1(format, print);
	}
	format = check_space(format, print);
	return (format);
}
