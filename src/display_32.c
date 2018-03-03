/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_32.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:33:51 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/28 14:34:01 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

int  check_display_cond32(t_ut u)
{
  if (!ft_strcmp("", u.str) || u.str[0] == '/' || (u.str[0] != '_'  && \
  !(u.str[0] == 'G' && u.str[1] == 'C') && \
  !(u.str[0] == 'd' && u.str[1] == 'y') && \
  !(u.str[0] == '-' && u.str[1] == '[') && \
  !(u.str[0] == '+' && u.str[1] == '[') && \
  !(u.str[0] == '.' && u.str[1] == 'o') && \
  !(u.str[0] == 'E' && u.str[1] == 'H') && \
  !(u.str[0] == 'L' && u.str[1] == 'C')))
    return (1);
  return (0);
}

void	display_addr32(t_env32 e, t_ut u, int *al_order)
{
  if ((u.len = ft_strlen(ft_lltoa(e.array[al_order[u.i]].n_value, 16))) < 8)
    u.len = 8 - u.len;
  while (u.len-- > 0)
    ft_putchar('0');
  ft_printf("%s", ft_lltoa(e.array[al_order[u.i]].n_value, 16));
}

int	 display_symbol_type32(t_env32 e, t_ut u, int *al_order, char *type)
{
  while (u.i < (int)e.sym->nsyms  && check_display_cond32(u))
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
    if ((e.array[al_order[u.i]].n_value) || (u.o == 1 && (type[al_order[u.i]] == 'T' || type[al_order[u.i]] == 't')))
      display_addr32(e, u, al_order);
    else
      ft_printf("        ");
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

void	  display_loop32(t_env32 e, t_ut u, int *al_order, char *type)
{
  u.i = -1;
  while (++u.i < (int)e.sym->nsyms)
  {
    u.str = ft_strdup(u.strtab + e.array[al_order[u.i]].n_un.n_strx);
    u.i = display_symbol_type32(e, u, al_order, type);
  }
}

int    print_output_32(t_env32 e, void *ptr, int o)
{
  t_ut u;
  char type[e.sym->nsyms];
  int  al_order[e.sym->nsyms];

  u.o = o;
  e.array = ptr + e.sym->symoff;
  u.strtab = ptr + e.sym->stroff;
  if (check_bin_limit(e.array) || check_bin_limit(u.strtab))
    return (1);
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
      tab_alpha_order32(al_order, e.array, u.strtab, u.i);
    u.i++;
  }
  display_loop32(e, u, al_order, type);
  return (0);
}
