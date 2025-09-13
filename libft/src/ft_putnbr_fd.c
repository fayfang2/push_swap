/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:10:47 by fay               #+#    #+#             */
/*   Updated: 2025/08/09 10:53:34 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = (long int)n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num >= 0 && num <= 9)
		ft_putchar_fd(num + '0', fd);
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
}

/* 	char	*c;

	c = ft_itoa(n);
	if (!c)
		return ;
	ft_putstr_fd(c, fd);
	free(c); */

/*
int main(void)
{
	int i = (-2147483647 -1);
	//	char buff[0xF0];
	
	//fd_to_buffer(2);
	ft_putnbr_fd(i, 2);
	write(2, "", 1);
	//get_fd_buffer(2, buff, 0xF0);
	//if (atoi(buff) == i)
	//	exit(2);
	exit(0);
	return 0;
}
*/