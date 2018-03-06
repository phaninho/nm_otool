/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:11:58 by stmartin          #+#    #+#             */
/*   Updated: 2018/03/03 23:53:07 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

t_env32				init_env32(void)
{
	t_env32			e;

	e.i = 0;
	e.j = 0;
	e.len = 0;
	e.segname = NULL;
	e.sectname = NULL;
	return (e);
}

void				alloc_and_copy32(t_env32 e)
{
	e.segname[e.j] = (char *)malloc(sizeof(char) * \
			(ft_strlen((e.k + e.sct32)->segname) + 1));
	e.segname[e.j][ft_strlen(e.sct32->segname)] = '\0';
	ft_strcpy(e.segname[e.j], (e.k + e.sct32)->segname);
	e.sectname[e.j] = (char *)malloc(sizeof(char) * \
			(ft_strlen((e.k + e.sct32)->sectname) + 1));
	e.sectname[e.j][ft_strlen(e.sct32->sectname)] = '\0';
	ft_strcpy(e.sectname[e.j], (e.k + e.sct32)->sectname);
}

t_env32				lc_segment_32(t_env32 e)
{
	e.sg32 = (struct segment_command *)e.lc;
	e.sct32 = (struct section *)((char *)e.sg32 + \
			sizeof(struct segment_command));
	e.len = e.len == 0 ? e.sg32->nsects : (e.len + e.sg32->nsects);
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
		alloc_and_copy32(e);
		e.k++;
		e.j++;
	}
	return (e);
}

int					handle_32(void *ptr, int o)
{
	t_env32			e;

	e = init_env32();
	e.header = (struct mach_header *)ptr;
	e.lc = ptr + sizeof(struct mach_header);
	if (check_bin_limit(e.header) || check_bin_limit(e.lc))
		return (ft_printf("Corrupted file\n"));
	while (e.i++ < (int)e.header->ncmds)
	{
		if (e.lc->cmd == LC_SEGMENT)
			e = lc_segment_32(e);
		if (e.lc->cmd == LC_SYMTAB)
		{
			e.sym = (struct symtab_command *)e.lc;
			if (check_bin_limit(e.sym))
				return (ft_printf("Corrupted file\n"));
			print_output_32(e, ptr, o);
			break ;
		}
		e.lc = (void *)e.lc + e.lc->cmdsize;
	}
	return (0);
}
