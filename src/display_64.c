/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:34:05 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/28 14:34:11 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/nm_otool.h"

int  check_display_cond(t_ut u)
{
  if (!ft_strcmp("", u.str) || u.str[0] == '/' || (u.str[0] != '_'  && \
  !(u.str[0] == 'G' && u.str[1] == 'C') && \
  !(u.str[0] == 'd' && u.str[1] == 'y') && \
  !(u.str[0] == '-' && u.str[1] == '[') && \
  !(u.str[0] == '+' && u.str[1] == '[')))
    return (1);
  return (0);
}

void	display_addr(t_env64 e, t_ut u, int *al_order)
{
  if ((u.len = ft_strlen(ft_lltoa(e.array[al_order[u.i]].n_value, 16))) < 16)
    u.len = 16 - u.len;
  while (u.len-- > 0)
    ft_putchar('0');
  ft_printf("%s", ft_lltoa(e.array[al_order[u.i]].n_value, 16));
}

int	 display_symbol_type(t_env64 e, t_ut u, int *al_order, char *type)
{
  while (u.i < (int)e.sym->nsyms  && check_display_cond(u))
  {
    u.i++;
    if (u.i < (int)e.sym->nsyms)
      u.str = ft_strdup(u.strtab + e.array[al_order[u.i]].n_un.n_strx);
    else if (u.str)
      free(u.str);
  }
  if (u.i >= (int)e.sym->nsyms)
    return (u.i);
  if (e.array[al_order[u.i]].n_type != 36 && \
    e.array[al_order[u.i]].n_type != 38 && e.array[al_order[u.i]].n_type != 32)
  {
    if ((e.array[al_order[u.i]].n_value) || (u.o == 1 && type[al_order[u.i]] == 'T'))
      display_addr(e, u, al_order);
    else
      ft_printf("                ");
    if (type[al_order[u.i]])
      ft_printf(" %c ", type[al_order[u.i]]);
    else
      ft_printf(" %d ", e.array[al_order[u.i]].n_type);
    ft_printf("%s\n",u.strtab + e.array[al_order[u.i]].n_un.n_strx);
  }
  if (u.str)
    free(u.str);
  return (u.i);
}

void	  display_loop(t_env64 e, t_ut u, int *al_order, char *type)
{
  u.i = -1;
  while (++u.i < (int)e.sym->nsyms)
  {
    u.str = ft_strdup(u.strtab + e.array[al_order[u.i]].n_un.n_strx);
    u.i = display_symbol_type(e, u, al_order, type);
  }
}

void    print_output_64(t_env64 e, void *ptr, int o)
{
  t_ut u;
  char type[e.sym->nsyms];
  int  al_order[e.sym->nsyms];

  u.o = o;
  e.array = ptr + e.sym->symoff;
  u.strtab = ptr + e.sym->stroff;
  u.i =-1;
  while (++u.i < (int)e.sym->nsyms)
    al_order[u.i] = u.i;
  u.i = 0;
  while (u.i < (int)e.sym->nsyms)
  {
    type[u.i] = e.array[u.i].n_type;
    if ((type[u.i] & N_STAB))
      type[u.i] = '-';
    else
      type[u.i] = define_symbol_type(type[u.i], e.array[u.i].n_value, \
        e.sectname[(int)e.array[u.i].n_sect - 1], \
        e.segname[(int)e.array[u.i].n_sect - 1]);
    if ((e.array[u.i].n_type & N_EXT) && type[u.i] != '?')
      type[u.i] = ft_toupper(type[u.i]);
    if (u.i > 0)
      tab_alpha_order64(al_order, e.array, u.strtab, u.i);
    u.i++;
  }
  display_loop(e, u, al_order, type);
}
