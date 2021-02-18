#ifndef LIBASM_H
# define LIBASM_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>

size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dst, const char *src);
int             ft_strcmp(const char* str1, const char* str2);
int             ft_write(int fd, const void *buf, size_t nbyte);
size_t          ft_read(int fildes, void *buf, size_t nbyte);
char*           ft_strdup(const char *s1);

#endif