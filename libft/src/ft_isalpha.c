/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:01:47 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:50:30 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_islower(int c)
{
	if (c < 'a' || c > 'z')
		return (0);
	return (1);
}

static int	ft_isupper(int c)
{
	if (c < 'A' || c > 'Z')
		return (0);
	return (1);
}

int	ft_isalpha(int c)
{
	if (ft_islower(c) || ft_isupper(c))
		return (1);
	return (0);
}
