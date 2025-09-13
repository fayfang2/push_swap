/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:10:43 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:50:59 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	size_t	ft_countchar(long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	long	num;
	size_t	len;

	num = n;
	len = ft_countchar(num);
	if (num == 0)
		return (ft_strdup("0"));
	itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	itoa[len--] = '\0';
	if (num < 0)
		num *= -1;
	while (num)
	{
		itoa[len--] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		itoa[0] = '-';
	return (itoa);
}

/* Check memory allocated to itoa, probably related to calculation of len.*/

/* #include <stdio.h>

int	main(void)
{
	int		n[] = {0, -1, 1, 10, 2147483647, -2147483648};	
	size_t	len = sizeof(n)/(sizeof(n[0]));
	int		d[len];
	char	*a[len];
	size_t	i;

	i = 0;
	while(i < len)
	{
		d[i] = ft_countchar(n[i]);
		a[i] = ft_itoa(n[i]);
		i++;
	}

	printf("Length of array is: %ld\n", len);
	printf("\n");

	i = 0;
	while (i < len)
	{
		printf("Test %ld:\n", i + 1);
		printf("Input n%ld		: %d\n", i + 1, n[i]);
		printf("Char count d%ld	: %d\n", i + 1, d[i]);
		printf("Output a%ld		: %s\n", i + 1, a[i]);
		printf("\n");
		free(a[i]);
		i++;
	}
	return (0);
} */