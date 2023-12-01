/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:03:13 by tkoulal           #+#    #+#             */
/*   Updated: 2023/11/30 23:22:54 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	isten(char *s)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

size_t	str_len(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

char	*str_dup(char *str)
{
	size_t	len;
	size_t	i;
	char	*new;

	if (str == NULL)
		return (NULL);
	len = str_len(str);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*str_cat(char *dest, char *src)
{
	size_t	end_dest;

	end_dest = 0;
	while (dest[end_dest])
		end_dest++;
	while (*src != '\0')
		dest[end_dest++] = *src++;
	dest[end_dest] = '\0';
	return (dest);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		return (str_dup(s2));
	str = malloc((str_len(s1) + str_len(s2) + 1));
	if (!str)
		return (NULL);
	str_cat(str, s1);
	str_cat(str, s2);
	return (str);
}
