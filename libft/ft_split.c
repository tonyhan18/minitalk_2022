/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:33:15 by chahan            #+#    #+#             */
/*   Updated: 2021/07/04 13:34:30 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_split_cnt(char const *s, char c)
{
	size_t	split_str;
	size_t	i;

	split_str = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		else if (s[i] != c)
		{
			split_str++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (split_str);
}

static char	**ft_free_str(char **str)
{
	size_t	cur_idx;

	cur_idx = 0;
	while (*(str + cur_idx))
		free(*(str + cur_idx));
	free(str);
	return ((char **) 0);
}

static size_t	ft_find_split(char const *s, char c, size_t *str_len)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = 0;
	i = 0;
	while (s[i] == c)
		i++;
	start = i;
	while (s[i] != c && s[i] != '\0')
		i++;
	end = i;
	*str_len = end - start;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	str_idx;
	size_t	str_len;
	size_t	row_idx;
	size_t	split_cnt;

	if (!s)
		return ((char **) 0);
	split_cnt = ft_get_split_cnt(s, c);
	str = (char **)malloc(sizeof(char *) * (split_cnt + 1));
	if (!(str))
		return ((char **) 0);
	row_idx = 0;
	str_idx = 0;
	while (row_idx < split_cnt)
	{
		str_idx += ft_find_split(s + str_idx, c, &str_len);
		str[row_idx] = (char *) malloc(str_len + 1);
		if (!str[row_idx])
			return (ft_free_str(str));
		ft_strlcpy(str[row_idx++], s + str_idx - str_len, str_len + 1);
	}
	str[row_idx] = (char *) 0;
	return (str);
}
