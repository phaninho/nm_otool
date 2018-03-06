/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:34:05 by stmartin          #+#    #+#             */
/*   Updated: 2018/03/05 20:00:56 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

int			check_display_cond(t_ut u)
{
	if (!ft_strcmp("", u.str) || u.str[0] == '/' || (u.str[0] != '_' && \
				!(u.str[0] == 'G' && u.str[1] == 'C') && \
				!(u.str[0] == 'd' && u.str[1] == 'y') && \
				!(u.str[0] == '-' && u.str[1] == '[') && \
				!(u.str[0] == '+' && u.str[1] == '[') && \
				!(u.str[0] == '.' && u.str[1] == 'o') && \
				!(u.str[0] == 'E' && u.str[1] == 'H') && \
				!(u.str[0] == 'L' && u.str[1] == 'C') && \
				!(u.str[0] == 'L' && u.str[1] == '_') && \
				!(u.str[0] == 'l' && u.str[1] == '_') && \
				!(u.str[0] == 's' && u.str[1] == 't') && \
				!(u.str[0] == 'f' && u.str[1] == 'u')))
		return (1);
	return (0);
}

void		display_addr(long unsigned int addr)
{
	int len;

	if ((len = ft_strlen(ft_lltoa(addr, 16))) < 16)
		len = 16 - len;
	while (len-- > 0)
		ft_putchar('0');
	ft_printf("%s	", ft_lltoa(addr, 16));
}

char		*ft_itoa_base_and_dup(int val, int base, int output_size)
{
	char			buffer[output_size + 1];
	char			*p;
	unsigned int	unsigned_val;

	unsigned_val = (unsigned int)val;
	if (base > 36 || base < 2)
		return (NULL);
	buffer[output_size] = 0;
	p = buffer + output_size - 1;
	*p = '0';
	if (unsigned_val > 0)
	{
		while (unsigned_val > 0)
		{
			*p-- = "0123456789abcdef"[unsigned_val % base];
			unsigned_val = unsigned_val / base;
			if (p < buffer)
				break ;
		}
		p++;
	}
	while (p > buffer)
		*--p = '0';
	return (ft_strdup(p));
}

void		display_section64(long unsigned int addr, unsigned int size,
		char *ptr)
{
	unsigned int	i;
	char			*str;

	i = 0;
	ft_printf("%s\n", "Contents of (__TEXT,__text) section");
	while (i < size)
	{
		if (i == 0 || i % 16 == 0)
		{
			if (i != 0)
				addr += 16;
			display_addr(addr);
		}
		str = ft_itoa_base_and_dup(ptr[i], 16, 2);
		ft_printf("%s ", str);
		if ((i + 1) % 16 == 0 && i + 1 < size)
			write(1, "\n", 1);
		i++;
	}
	if (str)
		free(str);
	write(1, "\n", 1);
}

int			print_output_otool_64(t_env64 e)
{
	int				print;

	print = 0;
	e.sg64 = (struct segment_command_64 *)e.lc;
	e.sct64 = (struct section_64 *)((char *)e.sg64 \
			+ sizeof(struct segment_command_64));
	if ((int)e.sg64->nsects)
	{
		ft_printf("%s:\n", e.av);
		display_section64(e.sct64->addr, e.sct64->size, \
				(char *)e.header + e.sct64->offset);
		print = 1;
	}
	return (print);
}
