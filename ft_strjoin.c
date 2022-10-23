/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:34:22 by hmochida          #+#    #+#             */
/*   Updated: 2022/10/23 14:59:14 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	d = malloc((len + 1) * sizeof(char));
	if (!d)
		return (0);
	while (i < len)
	{
		if (*s1)
			d[i++] = *s1++;
		else
			d[i++] = *s2++;
	}
	d[i] = '\0';
	return (d);
}
