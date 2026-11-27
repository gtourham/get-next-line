#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*out;
	size_t	i;
	size_t	j;

	out = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		out[i++] = s2[j++];
	out[i] = '\0';
	return (out);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*out;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	out = malloc(i + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		out[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		out[i++] = '\n';
	out[i] = '\0';
	return (out);
}
