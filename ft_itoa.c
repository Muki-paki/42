/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedosee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:44:16 by afedosee          #+#    #+#             */
/*   Updated: 2025/05/02 19:44:19 by afedosee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_num_len(int *n, int *len)
{
	char	*num;

	if (*n < 0)
	{
		num = (char *)malloc(sizeof(char) * (*len + 2));
		if (!num)
			return (NULL);
		*len = *len + 1;
		num[0] = '-';
		*n = *n * -1;
	}
	else
	{
		num = (char *)malloc(sizeof(char) * (*len + 1));
		if (!num)
			return (NULL);
	}
	return (num);
}

static char	*ft_zero(char *num)
{
	num = (char *)malloc(sizeof(char) * 2);
	if (!num)
		return (NULL);
	num[0] = '0';
	num[1] = '\0';
	return (num);
}

static char	*ft_min(char *num)
{
	int	len;
	int	n;

	n = 214748364;
	len = 10;
	num = (char *)malloc(sizeof(char) * 12);
	if (!num)
		return (NULL);
	num[len + 1] = '\0';
	num[len] = '8';
	while (n != 0)
	{
		num[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	num[0] = '-';
	return (num);
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		test;
	int		len;

	if (n == 0)
		return (ft_zero(NULL));
	else if (n == -2147483648)
		return (ft_min(NULL));
	test = n;
	len = ft_len(n);
	num = ft_num_len(&n, &len);
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (num);
}
