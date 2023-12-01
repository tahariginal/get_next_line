/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:35:40 by tkoulal           #+#    #+#             */
/*   Updated: 2023/12/01 22:46:46 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	tenlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
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
size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size != 0)
	{
		while (*(src + index) && --size)
			*(dest++) = *(src + index++);
		*dest = '\0';
	}
	while (*(src + index))
		index++;
	return (index);
}
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lenght_s1;
	size_t	lenght_s2;
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (str_dup(s2));
	if (!s2)
		return (str_dup(s1));
	lenght_s1 = str_len(s1);
	lenght_s2 = str_len(s2);
	dest = malloc(lenght_s1 + lenght_s2 + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, lenght_s1 + 1);
	ft_strlcpy(dest + lenght_s1, s2, lenght_s2 + 1);
	return (dest);
}
