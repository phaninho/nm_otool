/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:18:22 by stmartin          #+#    #+#             */
/*   Updated: 2018/03/07 21:22:50 by stmartin         ###   ########.fr       */
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

void	init_fat(t_fat *f, void *ptr)
{
	f->ppc = 0;
	f->fat_header = (struct fat_header *)ptr;
	f->arch = (void *)f->fat_header + sizeof(*f->fat_header);
	f->i = -1;
}

void	new_value(t_env64 *e, t_fat *f, void *ptr)
{
	f->offset = swap_bin(f->arch->offset, *(int *)ptr);
	e->header = (void *)ptr + f->offset;
}

int		handle_fat(void *ptr, char *av)
{
	t_fat					f;
	t_env64					e;

	init_fat(&f, ptr);
	while (++f.i < swap_bin(f.fat_header->nfat_arch, *(int *)ptr))
	{
		if (check_bin_limit(f.fat_header) || check_bin_limit(f.arch))
			return (ft_printf("Corrupted file\n"));
		new_value(&e, &f, ptr);
		if (check_bin_limit(e.header))
			return (ft_printf("%s is a corrupted file\n", av));
		f.ppc = (swap_bin(f.arch->cputype, *(int *)ptr) == CPU_TYPE_POWERPC || \
		swap_bin(f.arch->cputype, *(int *)ptr) == CPU_TYPE_POWERPC64) ? 1 : 0;
		ft_printf(f.ppc == 1 ? "\n%s (for architecture ppc):\n" : "", av);
		if (f.ppc && swap_bin(f.arch->cputype, *(int *)ptr) == CPU_TYPE_I386)
		{
			nm((void *)ptr + f.offset, av);
			ft_printf("\n%s (for architecture i386):\n", av);
		}
		else if (swap_bin(f.arch->cputype, *(int *)ptr) == CPU_TYPE_X86_64)
			break ;
		f.arch = (void *)f.arch + sizeof(*f.arch);
	}
	nm((void *)ptr + f.offset, av);
	return (0);
}
