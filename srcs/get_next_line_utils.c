#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (c == '\0' ? (char *)s : NULL);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*dup;
	size_t	i;

	dup = malloc(sizeof(char) * (ft_strlen_gnl(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_strdup_gnl("");
	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	return (join);
}
