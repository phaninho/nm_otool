/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:36:31 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/28 11:36:34 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/nm_otool.h"

char    define_symbol_type(char c, int addr_value, char *sct, char *seg)
{
  if ((c & N_TYPE) == N_UNDF)
  {
    c = 'u';
    if (addr_value != 0)
      c = 'c';
  }
  else if ((c & N_TYPE) == N_PBUD)
     c = 'u';
  else if ((c & N_TYPE) == N_ABS)
    c = 'a';
  else if ((c & N_TYPE) == N_SECT)
  {
    if (ft_strcmp(sct, SECT_TEXT) == 0 && ft_strcmp(seg, SEG_TEXT) == 0)
      c = 't';
    else if (ft_strcmp(sct, SECT_DATA) == 0 && ft_strcmp(seg, SEG_DATA) == 0)
      c = 'd';
    else if (ft_strcmp(sct, SECT_BSS) == 0 && ft_strcmp(seg, SEG_DATA) == 0)
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
