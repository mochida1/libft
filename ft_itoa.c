/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:12:29 by hmochida          #+#    #+#             */
/*   Updated: 2021/02/18 17:56:35 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		getintlen(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		sig;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = getintlen(n);
	sig = 0;
	if (n < 0)
	{
		n *= -1;
		sig = 1;
	}
	if (!(s = malloc(i + 1 * (sizeof(char)))))
		return (0);
	s[i--] = '\0';
	while (n >= 10)
	{
		s[i--] = '0' + (n % 10);
		n /= 10;
	}
	s[i] = '0' + (n % 10);
	if (sig)
		s[0] = '-';
	return (s);
}
