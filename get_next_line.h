/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:57:57 by rmaes             #+#    #+#             */
/*   Updated: 2022/06/13 19:33:25 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*extend_malloc(char	*str, int size, int ext, int fd);
int		linelen(char *str);
char	*get_next_line(int fd);
int		main(void);
void	*ft_calloc(unsigned long count, unsigned long size);
void	*ft_bzero(void *e, size_t len);
int		read_new(int fd, char *buf, int i, char **ret);
int		ft_strlen(const char *s);

#endif
