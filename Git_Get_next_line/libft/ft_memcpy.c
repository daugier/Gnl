/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:17:48 by daugier           #+#    #+#             */
/*   Updated: 2016/05/25 14:45:37 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t len)
{
	unsigned char	*tmp;

	if (dst && src)
		tmp = (unsigned char*)dst;
	while (len--)
		*tmp++ = *(unsigned char*)src++;
	return (dst);
}
