/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:35:12 by tkoulal           #+#    #+#             */
/*   Updated: 2023/12/01 22:47:07 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*((unsigned char *)s + n) = '\0';
}

char	*get_characters(char *holder, int fd)
{
	char	*str;
	ssize_t	i;
	char	*recall;

	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	i = 1;
	while (1)
	{
		bzero(str, BUFFER_SIZE);
		i = read(fd, str, BUFFER_SIZE);
		if (i <= 0)
			break ;
		str[i] = 0;
		recall = holder;
		holder = ft_strjoin(holder, str);
		free(recall);
		if (!holder)
			return (free(str), NULL);
	}
	if (i == -1)
	{
		free(holder);
		holder = NULL;
	}
	return (free(str), holder);
}

char	*get_line(char *holder)
{
	char	*line;
	int		i;

	if (!holder[0])
		return (NULL);
	i = tenlen(holder);
	line = malloc(i + 1);
	bzero(line, i + 1);
	i = 0;
	while (holder[i] && holder[i] != '\n')
	{
		line[i] = holder[i];
		i++;
	}
	if (holder[i] == '\n')
		line[i] = holder[i];
	return (line);
}

char	*get_rest(char *holder)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	i = tenlen(holder);
	if (holder[i] == '\0')
	{
		free(holder);
		return (NULL);
	}
	rest = malloc((str_len(holder) - i) + 1);
	if (!rest)
		return (NULL);
	j = 0;
	while (holder[i])
	{
		rest[j] = holder[i];
		i++;
		j++;
	}
	rest[j] = '\0';
	free(holder);
	return (rest);
}

char	*get_next_line(int fd)
{
	char *line;
	static char *holder[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	holder[fd] = get_characters(holder[fd], fd);
	if (!holder[fd])
		return (NULL);
	line = get_line(holder[fd]);
	holder[fd] = get_rest(holder[fd]);
	return (line);
}