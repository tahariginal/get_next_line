/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:03:13 by tkoulal           #+#    #+#             */
/*   Updated: 2023/11/24 23:03:05 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	isten(char *s)
{
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

char	*copy(char *s1, char *s2, char *dest)
{
	while (*s1)
	{
		*dest = *(char *)s1;
		dest++;
		s1++;
	}
	while (*s2)
	{
		*dest = *(char *)s2;
		dest++;
		s2++;
	}
	*dest = '\0';
	return (dest);
}

char	*str_dup(char *str)
{
	if (str == NULL)
		return (NULL);
	size_t	len;
	char	*new;
	size_t	i;

	len = str_len(str);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while(i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
char	*ft_strjoin(char  *s1, char  *s2)
{
	char	*str;

	if (!s1)
		return (str_dup("\0"));
	str = (char *)malloc((str_len(s1) + str_len(s2) + 1));
	if (str == NULL)
		return (NULL);
	copy(s1, s2, str);
	return (str);
}