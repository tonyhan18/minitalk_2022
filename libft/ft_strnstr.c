/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:14:36 by chahan            #+#    #+#             */
/*   Updated: 2021/07/02 21:50:30 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b_size;
	size_t	l_size;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	b_size = ft_strlen(big);
	l_size = ft_strlen(little);
	if (len == 0 || len < l_size || b_size == 0)
		return (NULL);
	i = 0;
	while (i < len - l_size + 1)
	{
		if (*(big + i) == *(little))
		{
			if (ft_strncmp(big + i, little, l_size) == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
