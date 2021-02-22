/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:18:58 by hmochida          #+#    #+#             */
/*   Updated: 2021/02/21 21:18:31 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;

	temp = lst;
	if (temp == NULL)
		return ;
	while (*temp)
	{
		temp->next = lst->next;
		del((*lst).content);
		free(lst);
		lst = NULL;
		temp = (*temp).next;
	}
}
