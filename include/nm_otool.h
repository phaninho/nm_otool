/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 15:51:56 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/23 15:52:02 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMO_TOOL_H
# define NMO_TOOL_H

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "../libft/includes/libft.h"
#include <mach-o/loader.h>
#include <mach-o/nlist.h>

typedef struct s_env
{

} t_env;

char  *ft_lltoa(long long val, int base);

#endif
