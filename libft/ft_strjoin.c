/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:18:03 by chahan            #+#    #+#             */
/*   Updated: 2021/07/02 19:04:10 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_mem;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s1 == 0)
		return (ft_strdup(s2));
	else if (!s2 && s2 == 0)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_mem = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_mem)
		return (NULL);
	ft_strlcpy(new_mem, s1, s1_len + 1);
	ft_strlcat(new_mem, s2, s1_len + s2_len + 1);
	return (new_mem);
}
