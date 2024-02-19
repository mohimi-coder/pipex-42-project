/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:03:29 by mohimi            #+#    #+#             */
/*   Updated: 2024/02/18 12:22:46 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_countword(char const *str, char c)
{
	int	i;
	int	count;
	int	b;

	i = 0;
	count = 0;
	b = 0;
	while (str[i])
	{
		if (str[i] != c && b == 0)
		{
			b = 1;
			count++;
		}
		else if (str[i] == c)
			b = 0;
		i++;
	}
	return (count);
}

static void	ft_free_split(char **words)
{
	int	i;

	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	int		wi;
	int		wl;
	char	**words;

	if (!s)
		return (NULL);
	wi = 0;
	wc = ft_countword(s, c);
	words = (char **)malloc (sizeof(char *) * (wc + 1));
	if (words == NULL)
		return (NULL);
	while (wi < wc)
	{
		while (*s == c)
			s++;
		wl = 0;
		while (s[wl] && s[wl] != c)
			wl++;
		words[wi] = ft_substr(s, 0, wl);
		if (!words[wi++])
			return (ft_free_split(words), NULL);
		s += wl;
	}
	return (words[wi] = NULL, words);
}
