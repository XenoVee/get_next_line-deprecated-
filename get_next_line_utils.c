/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:57:28 by rmaes             #+#    #+#             */
/*   Updated: 2022/08/02 20:09:45 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	ret = malloc((count * size) + 1);
	if (!ret)
		return (NULL);
	ft_bzero(ret, count * size);
	return (ret);
}

char	*extend_malloc(char	*str, int size, int ext)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_calloc(sizeof(char), (size + ext));
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

int	read_new(int fd, char *buf, int i)
{
	long int	rd;

	if (!buf[i])
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd > 0)
			buf[rd] = '\0';
		if (rd <= 0)
			return (-1);
		i = 0;
	}
	return (i);
}
