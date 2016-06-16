/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 18:32:32 by daugier           #+#    #+#             */
/*   Updated: 2016/06/16 16:13:20 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*cpy;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!(cpy = (char*)malloc(sizeof(char) * len + 1)) || !s || start > i)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		cpy[i++] = s[start++];
	cpy[i] = '\0';
	free((char*)s);
	return (cpy);
}
