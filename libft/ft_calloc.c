/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:26:28 by chahan            #+#    #+#             */
/*   Updated: 2021/07/01 23:26:30 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new_mem;

	new_mem = malloc(nmemb * size);
	if (!(new_mem))
		return (NULL);
	ft_bzero(new_mem, nmemb * size);
	return (new_mem);
}
