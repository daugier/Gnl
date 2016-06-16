/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:18:25 by daugier           #+#    #+#             */
/*   Updated: 2016/02/28 14:41:53 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	char *t_dst;
	char *t_src;

	t_src = (char*)src;
	t_dst = (char*)dst;
	while (len > 0 && *t_src != c)
	{
		len--;
		*t_dst++ = *t_src++;
	}
	if (len > 0)
	{
		*t_dst++ = *t_src++;
		return ((void*)t_dst);
	}
	else
		return (NULL);
}
