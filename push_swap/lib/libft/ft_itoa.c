/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:31:35 by ntome             #+#    #+#             */
/*   Updated: 2025/10/17 15:41:14 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_str_size(long int n)
{
	if (n < 0)
		return (1 + ft_get_str_size(n * -1));
	if (n < 10)
		return (1);
	return (1 + ft_get_str_size(n / 10));
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	len;
	long int		num;
	char			*str;

	num = n;
	len = ft_get_str_size(num);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = len - 1;
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	while (num >= 10)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
		i--;
	}
	str[i] = '0' + num;
	str[len] = '\0';
	return (str);
}
