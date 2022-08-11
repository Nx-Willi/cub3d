/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_piscine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:46:56 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/11 13:52:39 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_str_wordcount(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	while (str[i] && is_charset(str[i], charset))
		i++;
	words = 0;
	while (str[i])
	{
		while (str[i] && !is_charset(str[i], charset))
			i++;
		words++;
		while (str[i] && is_charset(str[i], charset))
			i++;
	}
	return (words);
}

char	*ft_strdup_2(char *str, char *charset)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i] && !is_charset(str[i], charset))
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (str[i] && !is_charset(str[i], charset))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split_piscine(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		n;
	int		words;

	words = ft_str_wordcount(str, charset);
	tab = malloc(sizeof(char *) * (words + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	n = 0;
	while (str[i] && n < words)
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		tab[n] = ft_strdup_2(&str[i], charset);
		if (tab[n] == 0)
			return (0);
		while (str[i] && !is_charset(str[i], charset))
			i++;
		n++;
	}
	tab[n] = 0;
	return (tab);
}
