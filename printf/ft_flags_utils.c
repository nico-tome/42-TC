/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:04:22 by ntome             #+#    #+#             */
/*   Updated: 2025/10/21 11:37:37 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_flag(const char c, va_list params)
{
	if (c == 'c')
		ft_write_char(va_arg(params, int));
	else if (c == 's')
		ft_write_str(va_arg(params, char *));
	else if (c == 'p')
		ft_write_ptr(va_arg(params, void *));
	else if (c == 'd' || c == 'i')
		ft_put_nbr(va_arg(params, int));
	else if (c == 'u')
		ft_write_unsigned(va_arg(params, unsigned int));
	else if (c == 'x' || c == 'X')
		ft_write_hexa(va_arg(params, unsigned int), c == 'x');
	else if (c == '%')
		ft_write_char('%');
}

int	ft_get_flag_size(const char c, va_list params)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (ft_strlen(va_arg(params, char *)));
	else if (c == 'p')
		return (ft_get_ptr_size(va_arg(params, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_get_int_size(va_arg(params, int)));
	else if (c == 'u')
		return (ft_get_unsigned_size(va_arg(params, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_get_hexa_size(va_arg(params, unsigned int)));
	else if (c == '%')
		return (1);
	return (0);
}
