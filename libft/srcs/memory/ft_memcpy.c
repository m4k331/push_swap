/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:37:10 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 21:47:37 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;

	pdst = (unsigned char*)dst;
	if (dst == src)
		return (dst);
	while (n--)
		*pdst++ = *(unsigned char*)src++;
	return (dst);
}
