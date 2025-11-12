/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 01:39:48 by ntome             #+#    #+#             */
/*   Updated: 2025/11/12 22:10:20 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_write_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_write_str("(null)"));
	while (str[i])
	{
		ft_write_char(str[i]);
		i++;
	}
	return (i);
}

int	ft_put_nbr(int nb)
{
	int	size;

	size = ft_get_int_size(nb);
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_put_nbr(nb * -1);
	}
	else
	{
		if (nb >= 10)
		{
			ft_put_nbr(nb / 10);
			ft_write_char(nb % 10 + '0');
		}
		else
			ft_write_char(nb % 10 + '0');
	}
	return (size);
}

int	ft_write_unsigned(unsigned int nb)
{
	int	size;

	size = ft_get_unsigned_size(nb);
	if (nb <= 0)
		ft_write_char('0');
	else if (nb < 10)
		ft_write_char(nb + '0');
	else
	{
		ft_write_unsigned(nb / 10);
		ft_write_char(nb % 10 + '0');
	}
	return (size);
}

int	ft_write_hexa(unsigned int nb, int lower)
{
	int	size;

	size = ft_get_hexa_size(nb);
	if (nb < 16)
	{
		if (nb < 10)
			ft_write_char(nb + '0');
		else
			ft_write_char((nb - 10) + ('A' + 32 * lower));
	}
	else
	{
		ft_write_hexa(nb / 16, lower);
		ft_write_hexa(nb % 16, lower);
	}
	return (size);
}
