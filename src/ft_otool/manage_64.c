/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:11:58 by stmartin          #+#    #+#             */
/*   Updated: 2018/03/05 19:58:41 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

t_env64				init_env64(char *av)
{
	t_env64			e;

	e.i = 0;
	e.j = 0;
	e.len = 0;
	e.segname = NULL;
	e.sectname = NULL;
	e.av = ft_strdup(av);
	return (e);
}

int					handle_otool_64(void *ptr, char *av)
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
			if (print_output_otool_64(e))
				break ;
		e.lc = (void *)e.lc + e.lc->cmdsize;
		if (check_bin_limit(e.lc))
			return (ft_printf("Corrupted file\n"));
	}
	return (0);
}
