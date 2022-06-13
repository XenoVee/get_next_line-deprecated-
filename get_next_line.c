/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:58:02 by rmaes             #+#    #+#             */
/*   Updated: 2022/06/13 15:04:01 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE];
	char			*ret;
	static int		i = 0;
	int				j;

	j = 0;
	while ((i != -1 || j == 0) && ret != NULL)
	{
		i = read_new(fd, buf, i);
		ret = extend_malloc(ret, j, BUFFER_SIZE, fd);
		while (buf[i] != '\n' && i < BUFFER_SIZE && buf[i] != '\0' && ret != 0)
		{
			ret[j] = buf[i];
			j++;
			i++;
		}
		if ((buf[i] == '\n' || j == 0) && ret != NULL)
		{
			ret[j] = buf[i];
			i++;
			ret[j + 1] = '\0';
			return (ret);
		}
	}
	return (ret);
}
