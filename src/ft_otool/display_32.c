/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_32.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:33:51 by stmartin          #+#    #+#             */
/*   Updated: 2018/03/05 16:08:59 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

void		display_section32(long unsigned int addr, unsigned int size,
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
			display_otool_addr(addr, 8);
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

int			print_output_otool_32(t_env32 e, int title)
{
	int				print;

	print = 0;
	e.sg32 = (struct segment_command *)e.lc;
	e.sct32 = (struct section *)((char *)e.sg32 \
			+ sizeof(struct segment_command));
	if ((int)e.sg32->nsects)
	{
		if (!title)
			ft_printf("%s:\n", e.av);
		display_section32(e.sct32->addr, e.sct32->size, \
				(char *)e.header + e.sct32->offset);
		print = 1;
	}
	return (print);
}
