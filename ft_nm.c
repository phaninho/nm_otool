#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include <mach-o/loader.h>
#include <mach-o/nlist.h>


void    print_output(int nsyms, int symoff, int stroff, void *ptr)
{
  int i;
  char *strtab;
  struct nlist_64 *array;

  array = ptr + symoff;
  strtab = ptr + stroff;
  i =-1;
  while (++i < nsyms)
  {
    printf("%s ", strtab + array[i].n_type);
    // if (strtab + array[i].n_type && !strcmp(strtab + array[i].n_type,  "assign_block"))
    //   printf("T ");
    // else if (!strcmp(strtab + array[i].n_type,  "_assign_block"))
    // printf("d ");
    // else
    //   printf("U ");
    printf("[%s]\n",strtab + array[i].n_un.n_strx);
  }

}


void handle_64(void *ptr)
{
  struct mach_header_64 *header;
  struct load_command       *lc;
  struct symtab_command   *sym;
  int   i;
  int ncmds;

  i = 0;
  header = (struct mach_header_64 *)ptr;
  ncmds = header->ncmds;
  // printf("ncmds %d\n", ncmds);
  lc = ptr + sizeof(*header);
  while (i++ < ncmds)
  {
    if (lc->cmd == LC_SYMTAB)
    {
      sym = (struct symtab_command *)lc;
      uint32_t cmd;
   printf("\ncmdsize=%d\n symoff=%d\n nsyms=%d\n stroff=%d\n strsize=%d\n\n",sym->cmdsize,  sym->symoff, sym->nsyms, sym->stroff,  sym->strsize);
      print_output(sym->nsyms, sym->symoff, sym->stroff, ptr);
      // printf("c'est le bon %d\n", sym->nsyms);
      break ;
    }
    lc = (void *)lc + lc->cmdsize;
  }
}

void  nm(void *ptr)
{
  int   magic_number;

  magic_number = *(int *)ptr;
  if (magic_number == MH_MAGIC_64)
    handle_64(ptr);
    // printf("binaire pour 64 bits\n");
  // printf("mh=>%d\n", MH_MAGIC_64);
}

int main(int ac, char **av)
{
  int fd;
  int i;
  char  *ptr;
  struct stat buff;

  i = 0;
  if (ac < 2)
    return (printf("Nombre d'arguments insuffisant\n"));
  while (++i < ac)
  {
    if (ac > 2)
      printf("%s:\n", av[i]);
    if ((fd = open(av[i], O_RDONLY)) < 0)
      return (printf("Open error\n"));
    if (fstat(fd, &buff) < 0)
      return (printf("fstat error\n"));
      printf("/// st_dev  %d\n", buff.st_dev);
      printf("/// st_ino  %llu\n", buff.st_ino);
      printf("/// st_mode  %d\n", buff.st_mode);
      printf("/// st_nlink %d\n", buff.st_nlink);
      printf("/// st_uid  %d\n", buff.st_uid);
      printf("/// st_gid  %d\n", buff.st_gid);
      printf("/// st_rdev %d\n", buff.st_rdev);
      printf("/// st_size %lld\n", buff.st_size);

    if ((ptr = mmap(0, buff.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
      return (printf("mmap error\n"));
    nm(ptr);
    if (munmap(ptr, buff.st_size) < 0)
      return (printf("munmap error\n"));
  }
  return (0);
}
