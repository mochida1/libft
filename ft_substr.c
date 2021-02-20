/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 22:28:13 by hmochida          #+#    #+#             */
/*   Updated: 2021/02/19 19:16:01 by hmochida         ###   ########.fr       */
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
		if (!(d = ft_calloc(1, (sizeof(char)))))
			return (0);
		return (d);
	}
	while (start--)
		s++;
	if (ft_strlen(s) - start >= len)
	{
		if (!(d = malloc((len + 1) * (sizeof(char)))))
			return (0);
	}
	else if (!(d = malloc((ft_strlen(s) - start + 1) * (sizeof(char)))))
		return (0);
	while (len-- && *s)
		d[i++] = *s++;
	d[i] = '\0';
	return (d);
}
