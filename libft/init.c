/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:31:23 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:31:25 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	init_struct(t_printf *printf)
{
	printf->ret = 0;
	printf->ret_wchar = 0;
	printf->valid = 0;
	printf->space_number = 0;
	printf->negatif = 0;
	printf->neg_sign = 0;
	printf->negatif_x = 0;
	printf->zero = 0;
	printf->d = 0;
	printf->ok = 0;
	printf->sharp = 0;
	printf->plus = 0;
	printf->space = 0;
	printf->point = 0;
	printf->precision_zero = 0;
	printf->precision_space = 0;
	printf->i = 0;
}
