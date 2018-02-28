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
  int fd;
  char  *ptr;
  struct stat buff;

  if ((fd = open(av, O_RDONLY)) <= 0)
  {
    ft_putendl("Open error");
    return (1);
  }
  if (fstat(fd, &buff) < 0)
  {
    ft_putendl("fstat error");
    return (1);
  }
  if ((ptr = mmap(0, buff.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
  {
    ft_putendl("mmap error");
    return (1);
  }
  nm(ptr);
  if (munmap(ptr, buff.st_size) < 0)
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
