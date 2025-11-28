/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:06:42 by ntome             #+#    #+#             */
/*   Updated: 2025/10/21 14:24:02 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_strlen("(null)"));
	while (str[i])
		i++;
	return (i);
}

int	ft_get_int_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_get_hexa_size(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

int	ft_get_unsigned_size(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_get_ptr_size(void *ptr)
{
	int			size;

	if (!ptr)
		return (ft_strlen("(nil)"));
	size = 2;
	size += ft_get_ptr_in_hexa_size((uintptr_t)ptr);
	return (size);
}
