/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedosee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:31:07 by afedosee          #+#    #+#             */
/*   Updated: 2025/05/01 20:31:11 by afedosee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*substr;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j])
		j++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	substr = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!substr)
		return (NULL);
	while (i < j)
		substr[k++] = s1[i++];
	substr[k] = '\0';
	return (substr);
}
