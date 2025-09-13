/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:48:26 by fayfang           #+#    #+#             */
/*   Updated: 2025/08/09 12:22:38 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printnbr(unsigned long nb, char c)
{
	int				count;
	unsigned long	blen;
	char			*base;

	count = 0;
	base = "0123456789abcdef";
	if (c == 'd' || c == 'i' || c == 'u')
		blen = 10;
	else
		blen = 16;
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb > blen - 1)
		count += ft_printnbr(nb / blen, c);
	count += ft_printchar(base[nb % blen]);
	return (count);
}

int	ft_printptr(void *p)
{
	int		count;
	size_t	ptr;

	count = 0;
	ptr = (size_t)(p);
	if (!p)
		count += ft_printstr("(nil)");
	else
		count += ft_printstr("0x") + ft_printnbr(ptr, 'p');
	return (count);
}
