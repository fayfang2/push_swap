/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:48:30 by fayfang           #+#    #+#             */
/*   Updated: 2025/08/09 12:18:39 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_type(const char c, va_list args)
{
	int		count;
	long	nb;

	count = 0;
	if (c == '%')
		return (ft_printchar('%'));
	else if (c == 'c')
		count = ft_printchar(va_arg(args, int));
	else if (c == 's')
		count = ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		count = ft_printptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
	{
		nb = va_arg(args, int);
		if (nb < 0)
		{
			count += ft_printchar('-');
			nb *= -1;
		}
		count += ft_printnbr(nb, c);
	}
	else if (c == 'x' || c == 'X' || c == 'u')
		count = ft_printnbr(va_arg(args, unsigned int), c);
	return (count);
}

int	ft_printf(const char *print, ...)
{
	va_list		args;
	size_t		i;
	int			count;

	if (!print)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, print);
	while (print[i])
	{
		if (print[i] == '%')
		{
			if (print[i + 1] == '\0' || !ft_strchr("cspdiuxX%%", print[i + 1]))
				return (va_end(args), -1);
			else
				count += ft_type(print[i + 1], args);
			i++;
			i++;
		}
		else
			count += ft_printchar(print[i++]);
	}
	va_end(args);
	return (count);
}
