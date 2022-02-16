/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:13:09 by chahan            #+#    #+#             */
/*   Updated: 2021/07/02 21:51:14 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	cur_idx;

	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	cur_idx = 0;
	while (cur_idx < dstsize - 1)
	{
		if (*(src + cur_idx) == '\0')
			break ;
		*(dest + cur_idx) = *(src + cur_idx);
		cur_idx++;
	}
	*(dest + cur_idx) = '\0';
	return (src_len);
}
