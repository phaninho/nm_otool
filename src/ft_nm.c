/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:11:54 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/28 11:11:55 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/nm_otool.h"

void  nm(void *ptr)
{
  int   magic_number;

  magic_number = *(int *)ptr;
  if (magic_number == (int)MH_MAGIC_64 || magic_number == (int)MH_CIGAM_64)
    handle_64(ptr);
  else
    ft_putendl("Not a 64 bit binary");
}

int	 read_args(char *av)
{
  int         fd;
  char        *ptr;
  struct stat buf;

  if ((fd = open(av, O_RDONLY)) <= 0 || (fstat(fd, &buff) < 0))
  {
    ft_putendl("Open or fstat error");
    return (1);
  }
  if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
  {
    ft_putendl("mmap error");
    return (1);
  }
  nm(ptr);
  if (munmap(ptr, buf.st_size) < 0)
  {
    ft_putendl("munmap error");
    return (1);
  }
  return (0);
}

int main(int ac, char **av)
{
  int i;

  i = 0;
  if (ac < 2)
  {
    ft_putendl("Nombre d'arguments insuffisant");
    return (1);
  }
  while (++i < ac)
  {
    if (ac > 2)
      ft_printf("\n%s:\n", av[i]);
    read_args(av[i]);
  }
  return (0);
}
