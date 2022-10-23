/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 22:28:13 by hmochida          #+#    #+#             */
/*   Updated: 2022/10/23 14:49:05 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	i = 0;
	if ((int)start > ft_strlen(s))
	{
		d = ft_calloc(1, (sizeof(char)));
		return (d);
	}
	while (start--)
		s++;
	if (ft_strlen(s) - start >= len)
		d = malloc((len + 1) * (sizeof(char)));
	else
		d = malloc((ft_strlen(s) - start + 1) * (sizeof(char)));
	while (len-- && *s)
		d[i++] = *s++;
	d[i] = '\0';
	return (d);
}
