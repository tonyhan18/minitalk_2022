/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:42:12 by chahan            #+#    #+#             */
/*   Updated: 2021/07/02 14:17:20 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*new_str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	sub_len = len;
	if (start + len > s_len)
		sub_len = (s_len - start);
	new_str = (char *) malloc(sizeof(char) * (sub_len + 1));
	if (!(new_str))
		return (NULL);
	ft_strlcpy(new_str, s + start, sub_len + 1);
	return (new_str);
}
