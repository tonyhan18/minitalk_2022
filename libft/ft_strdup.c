/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:29:23 by chahan            #+#    #+#             */
/*   Updated: 2021/07/02 19:06:41 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new_mem;
	int		str_len;

	str_len = ft_strlen(str);
	new_mem = (char *)malloc(str_len + 1);
	if (!new_mem)
		return (NULL);
	ft_strlcpy(new_mem, str, str_len + 1);
	return (new_mem);
}
