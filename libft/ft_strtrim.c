/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 02:00:35 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/10/23 23:55:02 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			cherch(const char *set, int c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char				*ft_strtrim(char const *s, char const *set)
{
	int			debut;
	int			fin;
	int			i;
	char		*p;

	debut = -1;
	if (!s || !set)
		return (NULL);
	fin = ft_strlen(s);
	while (s[++debut])
		if (!cherch(set, s[debut]))
			break ;
	while (debut < fin - 1)
		if (!cherch(set, s[fin - 1]))
			break ;
		else
			fin--;
	if (!(p = malloc(fin - debut + 1)))
		return (NULL);
	i = -1;
	while (++i < (fin - debut))
		p[i] = s[debut + i];
	p[i] = '\0';
	return (p);
}
