/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:14:36 by chahan            #+#    #+#             */
/*   Updated: 2021/07/02 20:03:36 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t n)
{
	int		ret;
	size_t	i;

	if ((b1 == 0 && b2 == 0) || n == 0)
		return (0);
	i = 0;
	ret = 0;
	while (i < n)
	{
		if (*((unsigned char *)b1 + i) != *((unsigned char *)b2 + i))
		{
			ret = *((unsigned char *)b1 + i) - *((unsigned char *)b2 + i);
			return (ret);
		}
		i++;
	}
	return (ret);
}
