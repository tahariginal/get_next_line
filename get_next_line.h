/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:44:07 by tkoulal           #+#    #+#             */
/*   Updated: 2023/12/01 22:47:34 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	ft_bzero(void *s, size_t n);
int		tenlen(char *str);
char	*get_next_line(int fd);
int		isten(char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	str_len(char *str);
char	*str_dup(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
