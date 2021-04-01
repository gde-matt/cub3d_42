/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-matt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:25:39 by gde-matt          #+#    #+#             */
/*   Updated: 2020/03/11 16:47:00 by gde-matt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	ft_bzero(void *s, unsigned long int n)
{
	unsigned char	*aux;

	aux = s;
	while (n > 0)
	{
		*aux = '\0';
		aux++;
		n--;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if (!(sub = malloc((len + 1) * sizeof(char))))
		return (0);
	if ((unsigned int)ft_strlen((char*)s) > start)
	{
		ft_memcpy(sub, (char*)s + start, len);
		sub[len] = 0;
	}
	else
		ft_bzero(sub, len + 1);
	return (sub);
}

int		final_line(char **string, char **line, int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (string[fd][i] != '\n' && string[fd][i] != '\0')
		i++;
	*line = ft_substr(string[fd], 0, i);
	if (string[fd][i] == '\n')
	{
		tmp = ft_strdup(&string[fd][i + 1]);
		free(string[fd]);
		string[fd] = tmp;
		if (string[fd][0] == '\0')
		{
			free(string[fd]);
			string[fd] = NULL;
		}
	}
	else
	{
		free(string[fd]);
		string[fd] = NULL;
		return (0);
	}
	return (1);
}

int		decision(char **string, char **line, int bytes, int fd)
{
	if (bytes < 0)
		return (-1);
	else if (bytes == 0 && string[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (final_line(string, line, fd));
}

int		get_next_line(int fd, char **line)
{
	ssize_t		bytes;
	char		buffer[BUFFER_SIZE + 1];
	static char	*str[2000];
	char		*strtmp;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			strtmp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = strtmp;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (decision(str, line, bytes, fd));
}
