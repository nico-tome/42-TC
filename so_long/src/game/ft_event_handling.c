/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:08:48 by ntome             #+#    #+#             */
/*   Updated: 2025/11/14 14:30:07 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"

void key_hook(int key, void* param)
{
    if(key == 41)
        mlx_loop_end((mlx_context)param);
}

void mouse_hook(int button, void* param)
{
	(void)button;
	(void)param;
}

void mouse_wheel_hook(int button, void* param)
{
    (void)button;
	(void)param;
}

void window_hook(int event, void* param)
{
    if(event == 0)
        mlx_loop_end((mlx_context)param);
}
