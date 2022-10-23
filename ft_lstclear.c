/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:18:58 by hmochida          #+#    #+#             */
/*   Updated: 2022/10/23 15:00:28 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_lis	*temp;

	temp = *lst;
	if (temp == NULL)
		return ;
	while (temp != NULL)
	{
		temp->next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		temp = (*temp).next;
	}
	*lst = NULL;
}
