/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:11:37 by chahan            #+#    #+#             */
/*   Updated: 2021/07/02 21:50:16 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int		len;

	if (n < 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_recursive_insert(char *buf, size_t *buf_idx, long long n)
{
	if (n == 0)
		return ;
	ft_recursive_insert(buf, buf_idx, n / 10);
	buf[(*buf_idx)++] = '0' + (n % 10);
	return ;
}

char	*ft_itoa(int n)
{
	char		*str;
	int			sign;
	size_t		n_len;
	size_t		buf_idx;
	long long	value;

	sign = 1;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		sign = -1;
	n_len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (NULL);
	buf_idx = 0;
	value = n;
	if (sign == -1)
	{
		str[buf_idx++] = '-';
		value *= -1;
	}
	ft_recursive_insert(str, &buf_idx, value);
	str[buf_idx] = '\0';
	return (str);
}
