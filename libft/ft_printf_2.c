/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:31:12 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:31:17 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

const char	*ft_printf_1(const char *format, t_printf *print)
{
	if (ft_isdigit(*format) == TRUE && *format != '0')
		format = take_precision(format, print);
	format = check_neg_sign(print, format);
	format = check_flag(format, print);
	format = check_flag(format, print);
	format = check_neg_sign(print, format);
	check_valid_specifier(format);
	if (print->precision_space > 0 && print->precision_zero <= 0)
		print->d = 1;
	if (*format == '%')
		format = if_percent(format, print);
	return (format);
}

const char	*ft_printf_2(const char *format, t_printf *print, va_list pa)
{
	if (*format != '%')
	{
		if (ft_isdigit(*format) == TRUE)
			format = count_espace(format, print);
		if (*format == '.' || *format == '+')
			format = if_point_or_plus(format, print);
		if (ft_isdigit(*format) == TRUE)
			format = if_is_digit(format, print);
		if (print->negatif == 1 && *format != 'x')
			print->zero = 0;
		while (print->precision_zero > 0 && ft_isdigit(*format) == 1)
			++format;
		if (*F == 'l' || *F == 'h' || *F == 'j' || *F == 'z' || *F == 's' ||
				*F == 'd' || *F == 'i' || *F == 'D' || *F == 'u')
			F = ft_printf_3(F, print, pa);
		else if (*F == 'U' || *F == 'p' || *F == 'o' || *F == 'O' ||
				*F == 'c' || *F == 'x' || *F == 'X' || *F == 'C' || *F == 'S')
			F = ft_printf_4(F, print, pa);
		else
			percent_no_specifier(format, print);
	}
	return (format);
}

const char	*ft_printf_3(const char *format, t_printf *print, va_list pa)
{
	if (*format == 'l')
		format = percent_l(pa, print, format);
	else if (*format == 'h')
		format = percent_h(pa, print, format);
	else if (*format == 'j')
		format = percent_j(pa, print, format);
	else if (*format == 'z')
		format = percent_z(pa, print, format);
	else if (*format == 's')
		percent_s(pa, print);
	else if (*format == 'd' || *format == 'i')
		percent_d(pa, print, format);
	else if (*format == 'D' || *format == 'u')
		percent_d_up(pa, print, format);
	return (format);
}

const char	*ft_printf_4(const char *format, t_printf *print, va_list pa)
{
	if (*format == 'U')
		percent_u_up(pa, print);
	else if (*format == 'p')
		percent_p(pa, print, format);
	else if (*format == 'o')
		percent_o(pa, print, format);
	else if (*format == 'O')
		percent_o_up(pa, print);
	else if (*format == 'c')
		format = percent_c(pa, print, format);
	else if (*format == 'x' || *format == 'X')
		format = percent_x(pa, print, format);
	else if (*format == 'C')
		percent_c_up(pa, print);
	else if (*format == 'S')
		percent_s_up(pa, print);
	return (format);
}
