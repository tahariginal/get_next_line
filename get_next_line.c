/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:43:58 by tkoulal           #+#    #+#             */
/*   Updated: 2023/12/01 21:42:10 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_characters(char *holder, int fd)
{
	char	*str;
	ssize_t	i;

	str = malloc(BUFFER_SIZE);
	if (!str)
		return (NULL);
	i = 1;
	while (1)
	{
		bzero(str, BUFFER_SIZE);
		i = read(fd, str, BUFFER_SIZE);
		if (i <= 0)
			break ;
		holder = ft_strjoin(holder, str);
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
	char		*line;
	static char	*holder;

	if (fd == -1 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	holder = get_characters(holder, fd);
	if (!holder)
		return (NULL);
	line = get_line(holder);
	holder = get_rest(holder);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*p;
	int		i;

	fd = open("src.txt", O_RDWR);
	i = 0;
	while (1)
	{
		p = get_next_line(fd);
		printf("%d >> \"%s\"\n", i++, p);
		if (p)
			free(p);
		else
			break ;
	}
	return (0);
}
