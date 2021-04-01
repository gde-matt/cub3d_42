/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-matt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:00:17 by gde-matt          #+#    #+#             */
/*   Updated: 2020/03/11 16:49:09 by gde-matt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, unsigned long int n)
{
	char *auxdst;
	char *auxsrc;

	if (!dst && !src)
		return (NULL);
	auxdst = dst;
	auxsrc = (char*)src;
	while (n > 0)
	{
		*auxdst = *auxsrc;
		auxdst++;
		auxsrc++;
		n--;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*dup;

	size = ft_strlen((char *)s1);
	if (!(dup = malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(dup, (char*)s1, size);
	dup[size] = 0;
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	int i;
	int len;

	len = ft_strlen((char*)s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*join;

	if (!s1)
		return (0);
	size = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!(join = malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(join, (char*)s1, ft_strlen((char*)s1));
	ft_memcpy(join + ft_strlen((char*)s1), (char*)s2, ft_strlen((char*)s2));
	join[size] = 0;
	return (join);
}
