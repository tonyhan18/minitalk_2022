/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:33:58 by chahan            #+#    #+#             */
/*   Updated: 2021/07/02 21:52:42 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dest);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	i = 0;
	while (i < dstsize - dst_len - 1)
	{
		if (*((char *)src + i) == '\0')
			break ;
		*(dest + dst_len + i) = *((char *)src + i);
		i++;
	}
	*(dest + dst_len + i) = '\0';
	return (dst_len + src_len);
}
