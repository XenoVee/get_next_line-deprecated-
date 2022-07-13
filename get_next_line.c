/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:58:02 by rmaes             #+#    #+#             */
/*   Updated: 2022/07/13 20:07:49 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		while (buf[*i] != '\n' && *i < BUFFER_SIZE && buf[*i] != '\0')
		{
			ret[j] = buf[*i];
			j++;
			(*i)++;
		}
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
