/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:13:23 by daugier           #+#    #+#             */
/*   Updated: 2016/05/25 16:48:41 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*t_src;
	char	*t_dst;
	size_t	i;

	i = 0;
	t_dst = (char *)dst;
	t_src = (char *)src;
	if (src < dst)
	{
		while (++i <= len)
			t_dst[len - i] = t_src[len - i];
	}
	else
	{
		while (len-- > 0)
			*t_dst++ = *t_src++;
	}
	return (dst);
}
