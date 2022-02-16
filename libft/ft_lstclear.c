/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:27:46 by chahan            #+#    #+#             */
/*   Updated: 2021/07/02 17:39:06 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur_node;
	t_list	*del_node;

	if (!(*lst))
		return ;
	cur_node = *lst;
	while (cur_node)
	{
		del(cur_node->content);
		del_node = cur_node;
		cur_node = cur_node->next;
		free(del_node);
	}
	*lst = (t_list *) 0;
	return ;
}
