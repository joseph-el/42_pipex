/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:42:48 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/12/17 08:50:20 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**clear_memory(char **error, int place)
{
	int	index;

	index = 0;
	while (index < place)
		free(error[index++]);
	free(error);
	return (NULL);
}

static int	count_words(char const *str, char c)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != c && *str)
		{
			while (*str != c && *str)
				str++;
			words++;
		}
	}
	return (words);
}

static char	**build_arrays(char **str, char const *s, int c, int save)
{
	int	index;
	int	place;

	index = 0;
	place = 0;
	while (s[place])
	{
		if (s[place] == c)
		{
			place++;
			continue ;
		}
		save = place;
		while (s[place] && s[place] != c)
			place++;
		str[index] = malloc(sizeof(char) * (place - save + 1));
		if (!str[index])
			return (clear_memory(str, index));
		ft_strlcpy(str[index], s + save, place - save + 1);
		index++;
	}
	str[index] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c, int start)
{
	char	**str;
	int		save;

	save = 0;
	if (!s)
		return (NULL);
	if (s + start)
		s += start;
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	build_arrays(str, s, c, save);
	return (str);
}
