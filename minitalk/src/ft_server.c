/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:16:10 by ntome             #+#    #+#             */
/*   Updated: 2025/11/05 15:03:24 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk.h"

char	*ft_add_char(char *str, char c)
{
	char	*tmp;
	int		i;

	if (!str || !c)
		return (NULL);
	tmp = malloc(sizeof(char) * ft_strlen(str) + 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(str);
	return (tmp);
}

char	*ft_setup_str(char *str)
{
	if (!str)
	{
		str = malloc(1);
		if (str)
			*str = 0;
	}
	return (str);
}

void	ft_get_signal(int signal)
{
	static char	*str;
	static int	power = 128;
	static char	result = 0;

	str = ft_setup_str(str);
	if (signal == SIGUSR2)
		result += power;
	power /= 2;
	if (power == 0)
	{
		power = 128;
		if (result == '\0')
		{
			ft_printf("%s", str);
			free(str);
			str = NULL;
		}
		else
			str = ft_add_char(str, result);
		result = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, ft_get_signal);
	signal(SIGUSR2, ft_get_signal);
	ft_printf("SERVER MANDA\nPID: %d\n", getpid());
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
