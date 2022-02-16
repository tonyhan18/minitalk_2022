/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:12:03 by chahan            #+#    #+#             */
/*   Updated: 2021/07/02 19:44:38 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (dst < src)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		}
		else
		{
			*((unsigned char *)dst + n - i - 1)
				= *((unsigned char *)src + n - i - 1);
		}
		i++;
	}
	return (dst);
}
