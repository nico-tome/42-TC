/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_codes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:48:41 by ntome             #+#    #+#             */
/*   Updated: 2025/11/11 18:55:41 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"
#include "../../includes/ft_error.h"

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
