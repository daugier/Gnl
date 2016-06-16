/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:56:15 by daugier           #+#    #+#             */
/*   Updated: 2016/05/25 16:48:42 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i])
	{
		if (ft_memcmp(big + i, little, ft_strlen(little)) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
