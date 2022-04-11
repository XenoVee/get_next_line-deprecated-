/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:57:28 by rmaes             #+#    #+#             */
/*   Updated: 2022/04/07 20:11:06 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a])
		a++;
	return (a);
}

size_t	lcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	len = ft_strlen(dst);
	while (src[i] && i + len + 1 < size)
	{
		dst[i + len] = src[i];
		i++;
	}
	while (src[i])
		i++;
	if (size < len)
		return (i + size);
	else
		return (len + i);
}
