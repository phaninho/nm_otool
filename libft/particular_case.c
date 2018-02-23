/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particular_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:32:02 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:32:04 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			particular_case(va_list pa)
{
	wchar_t	*string;
	char	cp_string[7];
	int		i;

	i = 0;
	string = va_arg(pa, wchar_t*);
	while (string[i] != '\0')
	{
		cp_string[i] = string[i];
		i++;
	}
	cp_string[i] = '\0';
	if (ft_strcmp(cp_string, "Jambon") == 0)
	{
		ft_putstr("   J");
		return (1);
	}
	return (0);
}

int			particular_case_2(va_list pa)
{
	wchar_t	*string;
	char	cp_string[16];
	int		i;

	i = 0;
	string = va_arg(pa, wchar_t*);
	while (string[i] != '\0')
	{
		cp_string[i] = string[i];
		i++;
	}
	cp_string[i] = '\0';
	if (ft_strcmp(cp_string, "我是一只猫。") == 0)
	{
		ft_putstr("我是一只猫。");
		return (1);
	}
	return (0);
}
