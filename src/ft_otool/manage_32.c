/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:11:58 by stmartin          #+#    #+#             */
/*   Updated: 2018/03/05 16:09:32 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

t_env32				init_env32(char *av)
{
	t_env32			e;

	e.i = 0;
	e.j = 0;
	e.len = 0;
	e.segname = NULL;
	e.sectname = NULL;
	e.av = ft_strdup(av);
	return (e);
}

int					handle_otool_32(void *ptr, char *av)
{
	t_env32			e;

	e = init_env32(av);
	e.header = (struct mach_header *)ptr;
	e.lc = ptr + sizeof(struct mach_header);
	if (check_bin_limit(e.header) || check_bin_limit(e.lc))
		return (ft_printf("Corrupted file\n"));
	while (e.i++ < (int)e.header->ncmds)
	{
		if (e.lc->cmd == LC_SEGMENT)
			if (print_output_otool_32(e))
				break ;
		e.lc = (void *)e.lc + e.lc->cmdsize;
		if (check_bin_limit(e.lc))
			return (ft_printf("Corrupted file\n"));
	}
	return (0);
}
