/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:58:02 by rmaes             #+#    #+#             */
/*   Updated: 2022/04/07 20:51:43 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// size_t	ft_strlen(const char *s)
// {
// 	int	a;

// 	a = 0;
// 	while (s[a])
// 		a++;
// 	return (a);
// }

// void	lcat(char *dst, const char *src, size_t size)
// {
// 	printf("test\n");

// 	size_t	i;
// 	size_t	len;

// 	len = 0;
// 	i = 0;
// 	if (dst)
// 		len = ft_strlen(dst);
// 	printf("test\n");
// 	while (src[i] && i + len + 1 < size)
// 	{
// 		dst[i + len] = src[i];
// 		i++;
// 	}
// }

char	*get_next_line(int fd)
{
	char		*buf;

	buf = malloc(sizeof(char) * 50);
	read(fd, buf, 5);
	printf("%s\n", buf);
	read(fd, buf, 5);
	printf("%s\n", buf);
	return (buf);
}
int	main(void)
{
	int	fd;
	char	*buf;

	fd = open("file.txt", O_RDONLY);
	buf = get_next_line(fd);
	close(fd);
	free(buf);
	printf("%s", buf);
}