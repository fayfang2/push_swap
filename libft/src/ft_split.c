/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:17:29 by fde-waal          #+#    #+#             */
/*   Updated: 2025/08/09 10:53:40 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (!i || (s[i] != c && s[i - 1] == c))
			n++;
		i++;
	}
	return (n);
}

static	size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	if (ft_strchr(s, c))
		len = ft_strchr(s, c) - s;
	else
		len = ft_strlen(s);
	return (len);
}

static	char	**ft_free(char **split, size_t j)
{
	while (j-- > 0)
		free(split[j]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	split = ft_calloc(sizeof(char *), (ft_wordcount(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		split[j++] = ft_substr(s, i, ft_wordlen(s + i, c));
		if (!split[j - 1])
			return (ft_free(split, j -1));
		i += ft_wordlen(s + i, c);
	}
	return (split);
}

/* static	void	ft_free(char **split, size_t j)
{
	while(j-- > 0)
		free(split[j]);
	free(split);
	if (!split[j])
	{
		ft_free(split, j);
		return (NULL);
	}
} */

/* 	char	**split;
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	start;

	split = malloc(sizeof(char *) * ft_wordcount(s, c) + 1);
	if (!split || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] != c)
		{
			if (s[i - 1] == c)
				start = i;
			len++;
			i++;
		}
		split[j++] = ft_substr(s, start, len + 1);
		i++;
	}
	split[j] = NULL;
	return (split); */

/* 	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
	
 #include <stdio.h>

int	main(void)
{
	char	*s;
	char	**split;
	char	c;
	size_t	i;
	size_t	n;

	s = "gggggghelloooogggg";
	c = 'g';
	n = ft_wordcount(s, c);
	split = ft_split("", ' ');
	// tab = ft_split("", ' ');
	i = 0;
	printf("Word count: %ld\n", n);
	while (split[i])
	{
		printf("Word %ld: %s\n", i + 1, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
} 
*/

/* int	main(void)
{
	// char	*s;
	char	**split;
	// char	c;
	size_t	i;
	// size_t	n;

	// s = "ggggg";
	// c = '';
	// n = ft_wordcount(s, c);
	// split = ft_split(s, c);
	split = ft_split("", 0);
	i = 0;
	printf("Word count: , %s\n", split[0]);
	while (split[i])
	{
		printf("Word %ld: %s\n", i + 1, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
} */

/* static	size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (s[i] != c)
		n++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			n++;
		i++;
	}
	return (n);
} */