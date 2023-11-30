#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


int isten(char *s);
size_t  str_len(char *str);
char	*str_dup(char *str);
char	*ft_strjoin(char  *s1, char  *s2);

#endif