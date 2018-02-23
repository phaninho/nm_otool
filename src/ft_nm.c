#include "../include/nm_otool.h"

int     is_in_alpha_order(char *str, char *cmp)
{
  int len_str;
  int len_cmp;
  int i;

  i = 0;
  len_str = ft_strlen(str);
  len_cmp = ft_strlen(cmp);
  while (i < len_str >= len_cmp ? len_cmp : len_str)
  {
    if (str[i] > cmp[i])
      return (1);
    else if (str[i] < cmp[i])
      return (0);
    i++;
  }
  return (0);
}

void	  tab_alpha_order(int *order, struct nlist_64 *array, char *strtab, int last)
{
  int t = 0;
  char *str;
  char *cmp;

  cmp = ft_strdup(strtab + array[last].n_un.n_strx);
  while (t < last)
  {
    str = ft_strdup(strtab + array[order[t]].n_un.n_strx);
    if (is_in_alpha_order(str, cmp))
    {
      ft_swap(&order[t], &order[last]);
      cmp = ft_strdup(strtab + array[order[last]].n_un.n_strx);
    }
    t++;
  }
}

int     check_tab_doubl(char *str, char *strtab, struct nlist_64 *array, int *tab, int lim)
{
  int   i;

  i = 0;
  while (i < lim)
  {
    if (!ft_strcmp(str, strtab + array[tab[i]].n_un.n_strx))
      return (1);
    i++;
  }
  return (0);
}

void    print_output(int nsyms, int symoff, int stroff, void *ptr, char **sgname, char **sctname)
{
  int i;
  // int run;
  char *strtab;
  struct nlist_64 *array;
  char type[nsyms];
  char *str;
  int  al_order[nsyms];

  array = ptr + symoff;
  strtab = ptr + stroff;
  i =-1;
  while (++i < nsyms)
    al_order[i] = i;
  i = 0;
  while (i < nsyms)
  {
    type[i] = array[i].n_type;
    if ((type[i] & N_STAB))
      type[i] = '-';
    else
    {
      if ((type[i] & N_TYPE) == N_UNDF)
      {
        type[i] = 'u';
        if ((array[i].n_value) != 0)
          type[i] = 'c';
      }
      else if ((type[i] & N_TYPE) == N_PBUD)
         type[i] = 'u';
      else if ((type[i] & N_TYPE) == N_ABS)
        type[i] = 'a';
      else if ((type[i] & N_TYPE) == N_SECT)
      {
        if (ft_strcmp(sctname[(int)array[i].n_sect - 1], SECT_TEXT) == 0 && ft_strcmp(sgname[(int)array[i].n_sect - 1], SEG_TEXT) == 0)
          type[i] = 't';
        else if (ft_strcmp(sctname[(int)array[i].n_sect - 1], SECT_DATA) == 0 && ft_strcmp(sgname[(int)array[i].n_sect - 1], SEG_DATA) == 0)
          type[i] = 'd';
        else if (ft_strcmp(sctname[(int)array[i].n_sect - 1], SECT_BSS) == 0 && ft_strcmp(sgname[(int)array[i].n_sect - 1], SEG_DATA) == 0)
          type[i] = 'b';
        else
          type[i] = 's';
      }
      else if ((type[i] & N_TYPE) == N_INDR)
        type[i] = 'i';
      else
        type[i] = '?';
    }

    if ((array[i].n_type & N_EXT) && type[i] != '?')
      type[i] = ft_toupper(type[i]);
    if (i > 0)
      tab_alpha_order(al_order, array, strtab, i);
    i++;
  }
  i = -1;
  while (++i < nsyms)
  {
    str = ft_strdup(strtab + array[al_order[i]].n_un.n_strx);
    while (i < nsyms  && (!ft_strcmp("", str) || str[0] == '/' || (str[0] != '_'  && !(str[0] == 'd' && str[1] == 'y'))))
    {
      i++;
      if (i < nsyms)
        str = ft_strdup(strtab + array[al_order[i]].n_un.n_strx);
      else if (str)
        free(str);
    }
    if (i >= nsyms)
      break;
    if (array[al_order[i]].n_type != 36 && array[al_order[i]].n_type != 38 && array[al_order[i]].n_type != 32)
    {
      if ((array[al_order[i]].n_value))
        printf("0000000%llx", array[al_order[i]].n_value);
      else
        printf("                ");
      if (type[al_order[i]])
        printf(" %c ", type[al_order[i]]);
      else
        printf(" %d ", array[al_order[i]].n_type);
      printf("%s\n",strtab + array[al_order[i]].n_un.n_strx);
    }
    if (str)
      free(str);
  }
}

void handle_64(void *ptr)
{
  struct mach_header_64 *header;
  struct load_command       *lc;
  struct symtab_command   *sym;
  struct section_64       *sct64;
  struct segment_command_64 *sg64;
  char   **segname;
  char   **sectname;
  int   i;
  int   j;
  int   k;
  int ncmds;
  int len;

  i = 0;
  j = 0;
  len = 0;
  segname = NULL;
  sectname = NULL;
  header = (struct mach_header_64 *)ptr;
  ncmds = header->ncmds;
  lc = ptr + sizeof(*header);

  while (i++ < ncmds)
  {
    if (lc->cmd == LC_SEGMENT_64)
    {

      sg64 = (struct segment_command_64 *)lc;
      sct64 = (struct section_64 *)((char *)sg64 + sizeof(struct segment_command_64));
      len = len == 0 ? sg64->nsects : (len + sg64->nsects);
      if (!segname && !sectname)
      {
        segname = (char **)malloc(sizeof(char *) * (len + 1));
        sectname = (char **)malloc(sizeof(char *) * (len + 1));
      }
      else if (len)
      {
        segname = (char **)realloc(segname, sizeof(char *) * (len + 1));
        sectname = (char **)realloc(sectname, sizeof(char *) * (len + 1));
      }
      segname[len] = NULL;
      sectname[len] = NULL;
      k = 0;
      while (j < len)
      {
        segname[j] = (char *)malloc(sizeof(char) * (ft_strlen((k + sct64)->segname) + 1));
        segname[j][ft_strlen(sct64->segname)] = '\0';
        ft_strcpy(segname[j], (k + sct64)->segname);
        sectname[j] = (char *)malloc(sizeof(char) * (ft_strlen((k + sct64)->sectname) + 1));
        sectname[j][ft_strlen(sct64->sectname)] = '\0';
        ft_strcpy(sectname[j], (k + sct64)->sectname);
        k++;
        j++;
      }
    }
    if (lc->cmd == LC_SYMTAB)
    {
      sym = (struct symtab_command *)lc;
      print_output(sym->nsyms, sym->symoff, sym->stroff, ptr, segname, sectname);
      break ;
    }
    lc = (void *)lc + lc->cmdsize;
  }
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

  if ((fd = open(av, O_RDONLY)) < 0)
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
    {
      ft_putstr("\n");
      ft_putstr(av[i]);
      ft_putendl(":");
    }
    return (read_args(av[i]));
  }
  return (0);
}
