/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-matt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:06:24 by gde-matt          #+#    #+#             */
/*   Updated: 2020/03/11 16:47:30 by gde-matt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
#include <fcntl.h>

# define BUFFER_SIZE 30

int		ft_strlen(char *str);
void	*ft_memcpy(void *dst, const void *src, unsigned long int n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		final_line(char **string, char **line, int fd);
int		decision(char **string, char **line, int bytes, int fd);
int		get_next_line(int fd, char **line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, unsigned long int n);
int     main(int argc, char *argv[]);

#endif
