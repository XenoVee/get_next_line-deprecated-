/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:58:02 by rmaes             #+#    #+#             */
/*   Updated: 2022/08/01 13:05:47 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	bufcopy(char *ret, char *buf, int *i, int j)
{
	while (buf[*i] != '\n' && *i < BUFFER_SIZE && buf[*i] != '\0')
	{
		ret[j] = buf[*i];
		j++;
		(*i)++;
	}
	return (j);
}

static char	*loop(char	*ret, char *buf, int fd, int *i)
{
	int	j;

	j = 0;
	while ((*i != -1 || j == 0))
	{	
		*i = read_new(fd, buf, *i, &ret);
		if (*i == -1 && ret == NULL)
			return (NULL);
		ret = extend_malloc(ret, j, BUFFER_SIZE, fd);
		if (ret == NULL)
			return (NULL);
		j = bufcopy(ret, buf, i, j);
		if (buf[*i] == '\n')
		{
			ret[j] = buf[*i];
			(*i)++;
			ret[j + 1] = '\0';
			return (ret);
		}
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	buf[BUFFER_SIZE + 1];
	static int	i = 0;

	str = NULL;
	return (loop(str, buf, fd, &i));
}
