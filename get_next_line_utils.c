/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:57:28 by rmaes             #+#    #+#             */
/*   Updated: 2022/06/10 16:06:15 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(unsigned long count, unsigned long size)
{
	char	*ret;

	ret = malloc((count * size));
	if (!ret)
		return (0);
	ft_bzero(ret, count * size);
	return (ret);
}

int	read_new(int fd, char *buf, int i)
{
	if (!buf[i] || i >= BUFFER_SIZE)
	{
		read(fd, buf, BUFFER_SIZE);
		i = 0;
	}
	return (i);
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

char	*extend_malloc(char	*str, int size, int ext)
{
	char	*ret;
	int		i;

	i = 0;
	if (size == 0)
	{
		ret = ft_calloc(sizeof(char), ext);
		return (ret);
	}
	ret = ft_calloc(sizeof(char), (size + ext));
	if (!ret)
		return (NULL);
	while (i < size)
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	return (ret);
}
