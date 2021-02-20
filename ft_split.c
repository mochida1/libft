/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:23:47 by hmochida          #+#    #+#             */
/*   Updated: 2021/02/19 15:17:32 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	splitlen(const char *s, char c, size_t i)
{
	size_t j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

static char		*subdup(const char *s, size_t i, char c)
{
	size_t	k;
	size_t	tmp;
	char	*dup;

	k = 0;
	if (!(dup = malloc((splitlen(s, c, i) + 1) * sizeof(char))))
		return (0);
	tmp = splitlen(s, c, i);
	while (k < tmp)
	{
		dup[k] = s[i];
		k++;
		i++;
	}
	dup[k] = '\0';
	return (dup);
}

static int		cagueta(const char *s, char c, size_t i)
{
	if (i == 0 && s[i] != c)
		return (1);
	else if (s[i] > 0 && s[i - 1] == c && s[i] != c)
		return (1);
	return (0);
}

static int		pcount(const char *s, char c)
{
	int		plen;
	size_t	i;

	i = 0;
	plen = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (cagueta(s, c, i))
			plen++;
		i++;
	}
	return (plen);
}

char			**ft_split(char const *s, char c)
{
	char	**p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(p = ft_calloc((pcount(s, c) + 1), sizeof(char *))))
		return (0);
	while (s[i])
	{
		if (cagueta(s, c, i))
		{
			if (!(p[j] = subdup(s, i, c)))
			{
				while ((int)--j >= 0)
					free(p[j]);
				free(p);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (p);
}
