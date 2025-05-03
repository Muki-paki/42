/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedosee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:21:21 by afedosee          #+#    #+#             */
/*   Updated: 2025/05/02 14:21:22 by afedosee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int		i;
	int		count;
	int		k;

	i = 0;
	count = 0;
	k = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			k = 0;
		else if (s[i] != c && k == 0)
		{
			count++;
			k = 1;
		}
		i++;
	}
	return (count);
}

static char	**memory(char **result, int words)

{
	int	f;

	f = 0;
	while (f < words)
	{
		free((void *)result[f]);
		f++;
	}
	free(result);
	return (NULL);
}

static char	**ft_body(char const *s, char c, char **result, int words)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c || s[i + 1] == '\0')
			k = k + 1;
		if ((s[i] == c && i - k + 1 > 0) || (s[i] != c && s[i + 1] == '\0'))
		{
			if (s[i] != c && s[i + 1] == '\0')
				i++;
			result[words] = ft_substr(s, k - 1, i - k + 1);
			if (!result[words])
				return (memory(result, words));
			result[words][i - k + 1] = '\0';
			k = i + 1;
			words++;
		}
		if (s[i] != '\0')
			i++;
	}
	result[words] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;

	words = 0;
	if (!s)
		return (NULL);
	result = (char **)ft_calloc(sizeof(char *), (ft_word_count(s, c) + 1));
	if (!result)
		return (NULL);
	return (ft_body(s, c, result, words));
}
