/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:53:37 by ntome             #+#    #+#             */
/*   Updated: 2025/10/21 14:27:34 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	params;

	i = 0;
	len = 0;
	va_start(params, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_print_flag(str[i], params);
		}
		else
		{
			len++;
			ft_write_char(str[i]);
		}
		i++;
	}
	va_end(params);
	return (len);
}
