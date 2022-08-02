/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:57:57 by rmaes             #+#    #+#             */
/*   Updated: 2022/08/02 20:33:02 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483646
#   undef BUFFER_SIZE
#  endif
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

char	*extend_malloc(char	*str, int size, int ext);
int		linelen(char *str);
char	*get_next_line(int fd);
void	*ft_calloc(unsigned long count, unsigned long size);
void	*ft_bzero(void *e, size_t len);
int		read_new(int fd, char *buf, int i);

#endif
