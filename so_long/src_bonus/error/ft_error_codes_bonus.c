/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_codes_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:48:41 by ntome             #+#    #+#             */
/*   Updated: 2025/11/20 14:10:03 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"
#include "../../includes_bonus/ft_error_bonus.h"

int	ft_is_error_code(int code)
{
	if (code >= 10 && code <= 99)
		return (TRUE);
	return (FALSE);
}

int	ft_is_succes_code(int code)
{
	if (code >= 100 && code <= 199)
		return (TRUE);
	return (FALSE);
}
