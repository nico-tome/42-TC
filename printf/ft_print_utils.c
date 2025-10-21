/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 01:39:48 by ntome             #+#    #+#             */
/*   Updated: 2025/10/21 12:39:43 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_char(const char c)
{
	write(1, &c, 1);
}

void	ft_write_str(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_write_str("(null)");
		return ;
	}
	while (str[i])
	{
		ft_write_char(str[i]);
		i++;
	}
}

void	ft_put_nbr(int	nb)
{
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
}

void	ft_write_unsigned(unsigned int nb)
{
	if (nb <= 0)
		ft_write_char('0');
	else if (nb < 10)
		ft_write_char(nb + '0');
	else
	{
		ft_write_char(nb % 10 + '0');
		ft_write_unsigned(nb / 10);
	}
}

void	ft_write_hexa(unsigned int nb, int upper)
{
	if (nb < 16)
	{
		if (nb < 10)
			ft_write_char(nb + '0');
		else
			ft_write_char((nb - 10) + ('A' + 32 * upper));
	}
	else
	{
		ft_write_hexa(nb / 16, upper);
		ft_write_hexa(nb % 16, upper);
	}
}

void	ft_write_ptr(void *ptr)
{
	if (!ptr)
	{
		ft_write_str("(nil)");
		return ;
	}
	ft_write_hexa((uintptr_t)ptr, 0);
}
