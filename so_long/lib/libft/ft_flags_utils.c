/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:04:22 by ntome             #+#    #+#             */
/*   Updated: 2025/11/12 22:10:03 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_flag(const char c, va_list params)
{
	if (c == 'c')
		return (ft_write_char(va_arg(params, int)));
	else if (c == 's')
		return (ft_write_str(va_arg(params, char *)));
	else if (c == 'p')
		return (ft_write_ptr(va_arg(params, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_put_nbr(va_arg(params, int)));
	else if (c == 'u')
		return (ft_write_unsigned(va_arg(params, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_write_hexa(va_arg(params, unsigned int), c == 'x'));
	else if (c == '%')
		return (ft_write_char('%'));
	return (0);
}
