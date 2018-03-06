/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:18:22 by stmartin          #+#    #+#             */
/*   Updated: 2018/03/04 00:18:24 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

int		check_bin_limit(void *ptr)
{
	if (ptr <= g_buf_limit)
		return (0);
	return (1);
}

int		swap_bin(int n, unsigned int magic_number)
{
	if (magic_number == FAT_MAGIC || magic_number == MH_MAGIC || \
		magic_number == MH_MAGIC_64)
		return (n);
	return (((n >> 24) & 0xff) | ((n << 8) & 0xff0000) | ((n >> 8) & 0xff00) | \
	((n << 24) & 0xff000000));
}

int		handle_fat(void *ptr, char *av)
{
	struct fat_header		*fat_header;
	struct fat_arch			*arch;
	int						offset;
	t_env64					e;
	int						i;
	int ppc;

	ppc = 0;
	fat_header = (struct fat_header *)ptr;
	arch = (void *)fat_header + sizeof(*fat_header);
	i = 0;
	while (i < swap_bin(fat_header->nfat_arch, *(int *)ptr))
	{
		if (check_bin_limit(fat_header) || check_bin_limit(arch))
			return (ft_printf("Corrupted file\n"));
		offset = swap_bin(arch->offset, *(int *)ptr);
		e.header = (void *)ptr + offset;
		if (check_bin_limit(e.header))
			return (ft_printf("%s is a corrupted file\n", av));
		if (swap_bin(arch->cputype, *(int *)ptr) == CPU_TYPE_POWERPC || \
		 swap_bin(arch->cputype, *(int *)ptr) == CPU_TYPE_POWERPC64)
		{
			ppc = 1;
		 	ft_printf("\n%s (for architecture ppc):\n", av);
		}
		else if (ppc && swap_bin(arch->cputype, *(int *)ptr) == CPU_TYPE_I386)
		{
			nm((void *)ptr + offset, av);
			if (ppc)
				ft_printf("\n%s (for architecture i386):\n", av);
		}
		else if (swap_bin(arch->cputype, *(int *)ptr) == CPU_TYPE_X86_64)
			break ;
		arch = (void *)arch + sizeof(*arch);
		i++;
	}
	nm((void *)ptr + offset, av);
	return (0);
}
