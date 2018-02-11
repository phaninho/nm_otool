/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 09:24:34 by stmartin          #+#    #+#             */
/*   Updated: 2016/03/03 11:29:25 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			free_mem(char **str)
{
	if (*str)
		ft_strdel(str);
}

static void			check_str(t_line *in, char **line, char **str)
{
	if ((in->chr = ft_strchr(*str, '\n')))
	{
		*line = ft_strsub(*str, 0, (size_t)(in->chr - *str));
		if (*(in->chr + 1))
			in->tmp = ft_strdup(in->chr + 1);
		else
			in->tmp = NULL;
		free_mem(&(*str));
		*str = in->tmp;
	}
	else
	{
		*line = *str;
		*str = NULL;
	}
}

static int			read_buffer(char **line, t_line *in, char **str)
{
	char	*tmp;

	if (!(in->chr = ft_strchr(in->buff, '\n')))
	{
		in->tmp = *line;
		*line = ft_strjoin(*line, in->buff);
		free_mem(&in->tmp);
		return (0);
	}
	else
	{
		in->tmp = *line;
		tmp = ft_strsub(in->buff, 0, (size_t)(in->chr - in->buff));
		*line = ft_strjoin(*line, tmp);
		free_mem(&tmp);
		free_mem(&(in->tmp));
		if (*(in->chr + 1))
			*str = ft_strdup(in->chr + 1);
		return (1);
	}
}

int					get_next_line(int const fd, char **line)
{
	static char		*str[256] = {NULL};
	t_line			in;

	in.chr = NULL;
	in.tmp = NULL;
	if (!line || fd < 0 || fd > 256 || !(in.buff = (char *)malloc(sizeof(char)
	* (BUFF_SIZE + 1))))
		return (-1);
	*line = NULL;
	if (str[fd])
		check_str(&in, line, &str[fd]);
	while (!in.chr && (in.oct = read(fd, in.buff, BUFF_SIZE)))
	{
		if (in.oct == -1)
			return (-1);
		in.buff[in.oct] = '\0';
		if (read_buffer(line, &in, &str[fd]))
			break ;
	}
	free_mem(&(in.buff));
	return (*line || str[fd] ? 1 : 0);
}
