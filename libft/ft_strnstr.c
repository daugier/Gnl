/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:28:37 by daugier           #+#    #+#             */
/*   Updated: 2016/05/20 16:22:29 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	j;

	i = 0;
	if (!little[i])
		return ((char *)big);
	j = ft_strlen(little);
	while (big[i] && len >= j)
	{
		if (ft_strncmp(big + i, little, j) == 0)
			return ((char *)big + i);
		i++;
		len--;
	}
	return (NULL);
}
