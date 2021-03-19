/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:18:15 by ocalamar          #+#    #+#             */
/*   Updated: 2020/12/01 12:43:18 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_line(char **line, char *buf, int flag)
{
	char	*tmp;

	if (flag)
	{
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	else
	{
		tmp = *line;
		*line = ft_strjoin(buf, "");
		free(tmp);
	}
	return (*line);
}

int		get_line_from_buf(char *buf, char **remainder, char **line)
{
	char	*p_to_n;

	p_to_n = 0;
	if ((p_to_n = ft_strchr(buf, '\n')))
	{
		*p_to_n = 0;
		if (!(*remainder = ft_strjoin(++p_to_n, "")))
			return (-1);
	}
	join_line(line, buf, 1);
	return (0);
}

int		check_remainder(char **line, char **remainder)
{
	char	*p_to_n;

	p_to_n = 0;
	if (*remainder)
	{
		if ((p_to_n = ft_strchr(*remainder, '\n')))
		{
			*p_to_n = 0;
			if (!join_line(line, *remainder, 1)
			|| !join_line(remainder, ++p_to_n, 0))
				return (-1);
		}
		else
		{
			if (!join_line(line, *remainder, 1))
				return (-1);
			free(*remainder);
			*remainder = 0;
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			read_byte;
	char		*buf;
	static char	*remainder;

	read_byte = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || !line || !(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	*line = ft_strjoin("", "");
	if (check_remainder(line, &remainder) < 0)
		return (-1);
	while (!remainder && (read_byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_byte] = 0;
		if (get_line_from_buf(buf, &remainder, line) < 0)
			return (-1);
	}
	free(buf);
	if (read_byte < 0)
		return (-1);
	return (read_byte || ft_strlen(remainder) || remainder ? 1 : 0);
}
