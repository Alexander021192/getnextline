/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocalamar <ocalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:16:23 by ocalamar          #+#    #+#             */
/*   Updated: 2020/11/20 13:16:30 by ocalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *src, char sym)
{
	if (src)
		while (*src != 0)
		{
			if (*src == sym)
				return (src);
			src++;
		}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*join;

	i = 0;
	if (!s1 && !s2)
		return (ft_strjoin("", ""));
	else if (s1 && !s2)
		return (ft_strjoin(s1, ""));
	else if (!s1 && s2)
		return (ft_strjoin(s2, ""));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = malloc(s1_len + s2_len + 1);
	if (join)
	{
		while (i < s1_len)
			join[i++] = *s1++;
		while (i < s1_len + s2_len)
			join[i++] = *s2++;
		join[s1_len + s2_len] = 0;
	}
	return (join);
}
