/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:36:31 by stmartin          #+#    #+#             */
/*   Updated: 2018/03/04 00:50:12 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

char	define_symbol_type_ut32(char *type, t_env32 e, t_ut u, int *al_order)
{
	if ((type[u.i] & N_STAB))
		type[u.i] = '-';
	else
		type[u.i] = define_symbol_type(type[u.i], e.array[u.i].n_value, \
				e.sectname[(int)e.array[u.i].n_sect - 1], \
				e.segname[(int)e.array[u.i].n_sect - 1]);
	if ((e.array[u.i].n_type & N_EXT) && type[u.i] != '?')
		type[u.i] = ft_toupper(type[u.i]);
	if (u.i > 0)
		if (al_ord32(al_order, e.array, u.strtab, u.i))
			return (-1);
	return (type[u.i]);
}

char	define_symbol_type_ut64(char *type, t_env64 e, t_ut u, int *al_order)
{
	if ((type[u.i] & N_STAB))
		type[u.i] = '-';
	else
		type[u.i] = define_symbol_type(type[u.i], e.array[u.i].n_value, \
				e.sectname[(int)e.array[u.i].n_sect - 1], \
				e.segname[(int)e.array[u.i].n_sect - 1]);
	if ((e.array[u.i].n_type & N_EXT) && type[u.i] != '?')
		type[u.i] = ft_toupper(type[u.i]);
	if (u.i > 0)
		if (al_ord64(al_order, e.array, u.strtab, u.i))
			return (-1);
	return (type[u.i]);
}

char	define_symbol_type(char c, int addr_value, char *sct, char *sg)
{
	if ((c & N_TYPE) == N_UNDF)
		c = (addr_value != 0) ? 'c' : 'u';
	else if ((c & N_TYPE) == N_PBUD)
		c = 'u';
	else if ((c & N_TYPE) == N_ABS)
		c = 'a';
	else if ((c & N_TYPE) == N_SECT)
	{
		if (ft_strcmp(sct, SECT_TEXT) == 0 && ft_strcmp(sg, SEG_TEXT) == 0)
			c = 't';
		else if (ft_strcmp(sct, SECT_DATA) == 0 && ft_strcmp(sg, SEG_DATA) == 0)
			c = 'd';
		else if (ft_strcmp(sct, SECT_BSS) == 0 && ft_strcmp(sg, SEG_DATA) == 0)
			c = 'b';
		else
			c = 's';
	}
	else if ((c & N_TYPE) == N_INDR)
		c = 'i';
	else
		c = '?';
	return (c);
}
