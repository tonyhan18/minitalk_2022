/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:33:34 by chahan            #+#    #+#             */
/*   Updated: 2021/07/02 20:22:23 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int			ret;
	size_t		i;

	i = 0;
	ret = 0;
	if (!s1 && !s2)
		return (ret);
	while (i < n)
	{
		if (*((char *)s1 + i) != *((char *)s2 + i)
			|| !*((char *)s1 + i) || !*((char *)s2 + i))
		{
			ret = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
			return (ret);
		}
		i++;
	}
	return (ret);
}
