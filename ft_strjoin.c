/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedosee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:21:34 by afedosee          #+#    #+#             */
/*   Updated: 2025/05/01 20:21:36 by afedosee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*substr;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	substr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!substr)
		return (NULL);
	while (*s1)
	{
		substr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		substr[i] = *s2;
		i++;
		s2++;
	}
	substr[i] = '\0';
	return (substr);
}
