/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:56:45 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:56:47 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_strcmp_ext(char *str, char *ext)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(str) - ft_strlen(ext);
	while (str[i] == ext[j] && str[i] != '\0')
	{
		i++;
		j++;
	}
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}
