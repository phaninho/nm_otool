/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:11:58 by stmartin          #+#    #+#             */
/*   Updated: 2018/03/05 16:09:35 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/nm_otool.h"

t_env64				init_env64(char *av)
{
	t_env64			e;

	e.i = 0;
	e.j = 0;
	e.len = 0;
	e.print = 0;
	e.segname = NULL;
	e.sectname = NULL;
	e.av = ft_strdup(av);
	return (e);
}

void				alloc_and_copy(t_env64 e)
{
	e.segname[e.j] = (char *)malloc(sizeof(char) * \
			(ft_strlen((e.k + e.sct64)->segname) + 1));
	e.segname[e.j][ft_strlen(e.sct64->segname)] = '\0';
	ft_strcpy(e.segname[e.j], (e.k + e.sct64)->segname);
	e.sectname[e.j] = (char *)malloc(sizeof(char) * \
			(ft_strlen((e.k + e.sct64)->sectname) + 1));
	e.sectname[e.j][ft_strlen(e.sct64->sectname)] = '\0';
	ft_strcpy(e.sectname[e.j], (e.k + e.sct64)->sectname);
}

t_env64				lc_segment_64(t_env64 e, void *ptr, int o)
{
	e.sg64 = (struct segment_command_64 *)e.lc;
	e.sct64 = (struct section_64 *)((char *)e.sg64 \
			+ sizeof(struct segment_command_64));
	e.len = e.len == 0 ? e.sg64->nsects : (e.len + e.sg64->nsects);
	if (!e.segname && !e.sectname)
	{
		e.segname = (char **)malloc(sizeof(char *) * (e.len + 1));
		e.sectname = (char **)malloc(sizeof(char *) * (e.len + 1));
	}
	else if (e.len)
	{
		e.segname = (char **)realloc(e.segname, sizeof(char *) * (e.len + 1));
		e.sectname = (char **)realloc(e.sectname, sizeof(char *) * (e.len + 1));
	}
	e.segname[e.len] = NULL;
	e.sectname[e.len] = NULL;
	e.k = 0;
	while (e.j < e.len)
	{
		alloc_and_copy(e);
		e.k++;
		e.j++;
	}
	e.print = print_output_64(e, ptr, o);
	return (e);
}

int					handle_otool_64(void *ptr, int o, char *av)
{
	t_env64			e;

	e = init_env64(av);
	e.header = (struct mach_header_64 *)ptr;
	e.lc = ptr + sizeof(struct mach_header_64);
	if (check_bin_limit(e.header) || check_bin_limit(e.lc))
		return (ft_printf("Corrupted file\n"));
	while (e.i++ < (int)e.header->ncmds)
	{
		if (e.lc->cmd == LC_SEGMENT_64)
			e = lc_segment_64(e , ptr, o);
		if (e.print)
			break;
		e.lc = (void *)e.lc + e.lc->cmdsize;
		if (check_bin_limit(e.lc))
			return (ft_printf("Corrupted file\n"));
	}
	return (0);
}
