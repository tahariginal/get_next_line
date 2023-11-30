/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:43:58 by tkoulal           #+#    #+#             */
/*   Updated: 2023/11/30 23:21:52 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_characters(char *holder, int fd)
{
	char	*str;
	ssize_t	i;

	str = malloc(BUFFER_SIZE);
	if (!str)
		return (NULL);
	i = 1;
	while (i && !isten(str))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[BUFFER_SIZE] = '\0';
		holder = ft_strjoin(holder, str);
		if (!holder)
		{
			free(str);
			return (NULL);
		}
	}
	free(str);
	return (holder);
}

char	*get_line(char *holder)
{
	char	*line;
	int		i;

	if (!holder[0])
		return (NULL);
	i = tenlen(holder);
	line = malloc(i + 1);
	i = 0;
	while (holder[i] && holder[i] != '\n')
	{
		line[i] = holder[i];
		i++;
	}
	if (holder[i] == '\n')
	{
		line[i] = holder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *holder)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (holder[i] && holder[i] != '\n')
		i++;
	if (holder[i] == '\n')
		i++;
	if (!holder[i])
		return (NULL);
	rest = malloc(str_len(holder) - i + 1);
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

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	holder = get_characters(holder, fd);
	if (!holder)
		return (NULL);
	line = get_line(holder);
	holder = get_rest(holder);
	return (line);
}

// int main()
// {
//     int fd = open("src.txt", O_RDWR);
//     char *p = get_next_line(fd);
//     printf("%s",p);
// }
