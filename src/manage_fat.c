#include "../include/nm_otool.h"
// t_envfat   init_envfat()
// {
//   t_envfat e;
//
//   e.i = 0;
//   e.j = 0;
//   e.len = 0;
//   e.segname = NULL;
//   e.sectname = NULL;
//   return (e);
// }

// int swap_endian(int n)
// {
//    return (((n>>24)&0xff) | // move byte 3 to byte 0
//                   ((n<<8)&0xff0000) | // move byte 1 to byte 2
//                   ((n>>8)&0xff00) | // move byte 2 to byte 1
//                   ((n<<24)&0xff000000));
// }

int		swap_bin(int n, unsigned int magic_number)
{
	if (magic_number == FAT_MAGIC || magic_number == MH_MAGIC || \
		magic_number == MH_MAGIC_64)
		return (n);
	return (((n >> 24) & 0xff) | ((n << 8) & 0xff0000) | ((n >> 8) & 0xff00) | \
	((n << 24) & 0xff000000));
}

void handle_fat(void *ptr, char *av)
{
	struct fat_header		*fat_header;
	struct fat_arch			*arch;
	int	offset;
	t_env64		e;
	int				i;
	unsigned int   		magic_number;


	magic_number = *(int *)ptr;
	fat_header = (struct fat_header *)ptr;
	arch = (void *)fat_header + sizeof(*fat_header);
	offset = swap_bin(arch->offset, magic_number);
	i = 0;
	while (i < swap_bin(fat_header->nfat_arch, magic_number))
	{
		offset = swap_bin(arch->offset, magic_number);
		e.header = (void *)ptr + offset;
		if (swap_bin(arch->cputype, magic_number) == CPU_TYPE_X86_64)
			break ;
		arch = (void *)arch + sizeof(*arch);
		// if (check_range_addr(arch) || check_range_addr(header))
			// return (print_error("file", "truncated or malformed object"));
		i++;
	}
	e.header = (void *)ptr + offset;
  nm((void *)e.header, av);
}
