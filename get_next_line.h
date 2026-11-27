#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# ifndef BUF_SIZE
#  define BUF_SIZE 42
# endif


char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif
