/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:23:35 by chahan            #+#    #+#             */
/*   Updated: 2021/07/02 19:08:45 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(int c, const char *set)
{
	if (ft_strchr(set, c))
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new_mem;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (ft_isset(*(s1 + start), set) && *(s1 + start) != '\0')
		start++;
	while (ft_isset(*(s1 + end), set) && (s1 + end) != s1)
		end--;
	if (start > end)
		return (ft_strdup(""));
	new_mem = (char *) malloc(sizeof(char) * (end - start + 1 + 1));
	if (!(new_mem))
		return (NULL);
	ft_strlcpy(new_mem, s1 + start, end - start + 1 + 1);
	return (new_mem);
}
