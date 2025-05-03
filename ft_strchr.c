/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedosee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:11:23 by afedosee          #+#    #+#             */
/*   Updated: 2025/05/01 17:11:24 by afedosee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)str;
	i = 0;
	while ((*(ptr + i) != (char)c) && (*(ptr + i) != '\0'))
		i++;
	if (*(ptr + i) == (char)c)
		return (ptr + i);
	else
		return (0);
}
