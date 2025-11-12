/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:23:19 by ntome             #+#    #+#             */
/*   Updated: 2025/11/12 22:10:38 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_ptr_in_hexa_size(uintptr_t nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		size++;
	}
	return (size);
}

void	ft_write_ptr_in_hexa(uintptr_t nb)
{
	if (nb < 16)
	{
		if (nb < 10)
			ft_write_char(nb + '0');
		else
			ft_write_char(nb - 10 + 'a');
	}
	else
	{
		ft_write_ptr_in_hexa(nb / 16);
		ft_write_ptr_in_hexa(nb % 16);
	}
}

int	ft_write_ptr(void *ptr)
{
	int	size;

	size = ft_get_ptr_size(ptr);
	if (!ptr)
	{
		ft_write_str("(nil)");
		return (size);
	}
	ft_write_str("0x");
	ft_write_ptr_in_hexa((uintptr_t)ptr);
	return (size);
}
