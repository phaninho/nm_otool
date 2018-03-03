/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 15:51:56 by stmartin          #+#    #+#             */
/*   Updated: 2018/03/03 23:43:30 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include <sys/mman.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../libft/includes/libft.h"
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>
# include <ar.h>

void							*g_buf_limit;
typedef struct s_env32			t_env32;
typedef struct s_env64			t_env64;
typedef struct s_ut				t_ut;
typedef struct s_arlst			t_arlst;

struct							s_ut
{
	int							i;
	int							len;
	int							o;
	char						*strtab;
	char						*str;
};

struct							s_arlst
{
	uint32_t					off;
	uint32_t					strx;
	struct s_arlst				*next;
};

struct							s_env32
{
	int							i;
	int							j;
	int							k;
	int							len;
	char						**segname;
	char						**sectname;
	struct mach_header			*header;
	struct load_command			*lc;
	struct symtab_command		*sym;
	struct section				*sct32;
	struct segment_command		*sg32;
	struct nlist				*array;
};

struct							s_env64
{
	int							i;
	int							j;
	int							k;
	int							len;
	char						**segname;
	char						**sectname;
	struct mach_header_64		*header;
	struct load_command			*lc;
	struct symtab_command		*sym;
	struct section_64			*sct64;
	struct segment_command_64	*sg64;
	struct nlist_64				*array;
};

void							nm(void *ptr, char *av);
int								print_output_32(t_env32 e, void *ptr, int o);
int								print_output_64(t_env64 e, void *ptr, int o);
void							tab_alpha_order32(int *order,
		struct nlist *array, char *strtb, int l);
void							tab_alpha_order64(int *order,
		struct nlist_64 *arr, char *strtb, int l);
int								handle_32(void *ptr, int o);
int								handle_64(void *ptr, int o);
int								handle_fat(void *ptr, char *av);
int								handle_archive(void *ptr, char *av);
int								check_bin_limit(void *ptr);
char							define_symbol_type(char c, int addr_value,
		char *sct, char *seg);

#endif
