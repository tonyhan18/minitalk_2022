/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:56:18 by chahan            #+#    #+#             */
/*   Updated: 2021/06/30 12:08:42 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	d;
	size_t			i;

	mem = dest;
	d = c;
	i = 0;
	while (i++ < n)
		*mem++ = d;
	return (dest);
}
