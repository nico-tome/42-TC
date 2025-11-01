/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:08:33 by ntome             #+#    #+#             */
/*   Updated: 2025/10/17 16:13:28 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int c, int fd)
{
	if (c == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (c < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-c, fd);
	}
	else
	{
		if (c >= 10)
			ft_putnbr_fd(c / 10, fd);
		ft_putchar_fd('0' + c % 10, fd);
	}
}
