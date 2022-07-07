/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:57:28 by rmaes             #+#    #+#             */
/*   Updated: 2022/07/07 16:47:33 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a])
		a++;
	return (a);
}

void	*ft_bzero(void *e, size_t len)
{
	size_t	a;

	a = 0;
	while (a < len)
	{
		((char *)e)[a] = 0;
		a++;
	}
	return (e);
}

void	*ft_calloc(unsigned long count, unsigned long size)
{
	char	*ret;

	ret = malloc((count * size));
	if (!ret)
		return (NULL);
	ft_bzero(ret, count * size);
	return (ret);
}

char	*extend_malloc(char	*str, int size, int ext, int fd)
{
	char	*ret;
	int		i;

	i = 0;
	if (fd < 0 || fd == 1 || fd == 2 || fd > 999 || str == NULL)
	{
		if (size != 0)
			free(str);
		return (NULL);
	}
	ret = ft_calloc(sizeof(char), (size + ext + 1));
	if (size == 0)
		return (ret);
	while (i < size && ret)
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	return (ret);
}

int	read_new(int fd, char *buf, int i, char **ret)
{
	long int	rd;
	int			fst;

	if (!buf[0])
		fst = 1;
	else
		fst = 0;
	if (!buf[i] || i >= BUFFER_SIZE)
	{
		ft_bzero(buf, BUFFER_SIZE);
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == 0 && fst == 1)
		{
			*ret = 0;
			return (-1);
		}
		else if (rd == 0)
			return (-1);
		i = 0;
	}
	return (i);
}
