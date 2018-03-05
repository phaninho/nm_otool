/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:34:05 by stmartin          #+#    #+#             */
/*   Updated: 2018/03/04 00:31:06 by stmartin         ###   ########.fr       */
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

void		display_addr(t_env64 e, t_ut u)
{
	if ((u.len = ft_strlen(ft_lltoa(e.array[u.i].n_value, 16))) < 16)
		u.len = 16 - u.len;
	while (u.len-- > 0)
		ft_putchar('0');
	ft_printf("%s", ft_lltoa(e.array[u.i].n_value, 16));
}

int			display_symbol_type(t_env64 e, t_ut u)
{
	while (u.i < (int)e.sym->nsyms && check_display_cond(u))
	{
		// if (++u.i < (int)e.sym->nsyms)
		// 	u.str = ft_strdup(u.strtab + e.array[u.i].n_un.n_strx);
		// else if (u.str)
		// 	free(u.str);
	}
	if (u.i >= (int)e.sym->nsyms)
		return (u.i);
	if (e.array[u.i].n_type != 36 && \
	e.array[u.i].n_type != 38 && e.array[u.i].n_type != 32 && !ft_strcmp(e.segname[u.i], SEG_TEXT))
	{
		if (e.array[u.i].n_value)
			display_addr(e, u);
		else
			ft_printf("                ");
		// if (type[[u.i])
		// 	ft_printf(" %c ", type[al_order[u.i]]);
		// else
		// 	ft_printf(" %d ", e.array[al_order[u.i]].n_type);
		ft_printf("%s %s\n", u.strtab + e.array[u.i].n_un.n_strx, e.sectname[u.i]);
	}
	free(u.str ? u.str : 0);
	return (u.i);
}

void			display_section64(long unsigned int addr, unsigned int size,
	char *ptr)
{
	unsigned int	i;
	char			*str;

	i = 0;
	ft_printf("%s\n", "Contents of (__TEXT,__text) section");
	while (i < size)
	{
		// ft_printf("1\n");

		if (i == 0 || i % 16 == 0)
		{
			if (i != 0)
				addr += 16;
			ft_printf("%016llx\t", addr);
		}
		// ft_printf("2\n");

		str = ft_lltoa(ptr[i], 16);
		// ft_printf("3\n");

		if (str)
		{
			// ft_printf("3bis %s \n", str);
			str = ft_strsub(str, ft_strlen(str) - ft_strlen(str) == 2 ? 2 : 1, 2);
			// ft_printf("4\n");

			ft_printf("%s ", str ? str : "00");
		// ft_printf("5\n");

		free(str);
		// ft_printf("6\n");
		}
		// ft_printf("6bis\n");

		if ((i + 1) % 16 == 0 && i + 1 < size)
			write(1, "\n", 1);
		i++;
		// ft_printf("7\n");

		// ft_printf(" %d sur %d\n", i, size);
	}
	write(1, "\n", 1);
}

void		display_loop(t_env64 e, t_ut u)
{
	u.i = -1;
	// e.sg64 = (struct segment_command_64 *)e.header + sizeof(struct mach_header_64);
	// while (!(int)e.sg64->nsects)
	// 	e.sg64 = (struct segment_command_64 *)e.header + sizeof(struct mach_header_64) + e.lc->cmdsize;

	ft_printf("ok %d\n", (int)e.sg64->nsects);
	while (++u.i < (int)e.sg64->nsects)
	{
		ft_printf("la %d \n", u.i);
		// u.str = ft_strdup(u.strtab + e.array[u.i].n_un.n_strx);
		display_section64(e.sct64->addr, e.sct64->size, (char *)e.header + e.sct64->offset);
		// e.sct64 = (void *)e.sct64 + sizeof(*e.sct64);

	}
}

int			print_output_64(t_env64 e, void *ptr, int o)
{
	t_ut	u;
	// char	type[e.sym->nsyms];
	// int		al_order[e.sym->nsyms];
	u.o = o;

	(void)ptr;
	// e.array = ptr + e.sym->symoff;
	// u.strtab = ptr + e.sym->stroff;

	// if (check_bin_limit(e.array) || check_bin_limit(u.strtab))
	// 	return (1);
	// u.i = -1;
	// while (++u.i < (int)e.sym->nsyms)
	// 	al_order[u.i] = u.i;
	// u.i = 0;
	// while (u.i < (int)e.sym->nsyms)
	// {
	// 	type[u.i] = e.array[u.i].n_type;
	// 	type[u.i] = define_symbol_type_ut64(type, e, u, al_order);
	// 	u.i++;
	// }

	display_loop(e, u);
	return (0);
}
