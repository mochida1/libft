/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 00:03:52 by hmochida          #+#    #+#             */
/*   Updated: 2021/02/22 01:24:38 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *temp;

	temp = lst;
	if (temp == NULL)
		return(0);
	while(lst)
	{

		temp->content = ft_lstmapp(f(temp->content));
	}
}


/*Iterates the list ’lst’ and applies the function
’f’ to the content of each element. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of an element if needed.*/


	/*We then make sure that both the list passed as well as the function f are
	 *not NULL. If they are we will return NULL. If not we will run the function
	 f on the link lst and set it into our newlist link variable. NOTE: We are
	 to assume that the function f allocates memory for our newlist variable
	 based on the data of lst. We then check if newlist is null as well as if
	 the link lst's element next is NULL. If neither are NULL we set our newlist
	 element next equal to the ft_lstmap function which has been passed lst's
	 element next (the link following it) as well as the function f. This allows
	 us to recursively apply the function f to all of the links and allows us to
	 allocate memory based on how many indiviual links we have in our list. Once
	 lst->next becomes equal to NULL this will break us out of the recursion and
	 have us return the newlist.*/
