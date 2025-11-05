/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:52:11 by ntome             #+#    #+#             */
/*   Updated: 2025/11/05 17:57:24 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk.h"

char	*ft_add_char(char *str, char c)
{
	char	*tmp;
	int		i;
	int		len;

	if (!str || !c)
		return (NULL);
	len = ft_strlen(str);
	tmp = malloc(sizeof(char) * len + 2);
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

void	ft_get_signal(int signal, siginfo_t *signal_infos, void *nptr)
{
	static char				*str;
	static int				power = 128;
	static unsigned char	result = 0;

	(void)nptr;
	str = ft_setup_str(str);
	if (signal == SIGUSR2)
		result += power;
	ft_printf("power: %d, result: %d\n", power, result);
	power /= 2;
	if (power == 0)
	{
		power = 128;
		if (result == '\0')
		{
			ft_printf("%s", str);
			free(str);
		str = NULL;
			kill(signal_infos->si_pid, SIGUSR1);
		}
		else
			str = ft_add_char(str, result);
		result = 0;
	}
}

int	main(void)
{
	struct sigaction	signal_infos;

	signal_infos.sa_sigaction = ft_get_signal;
	sigemptyset(&signal_infos.sa_mask);
	signal_infos.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal_infos, NULL);
	sigaction(SIGUSR2, &signal_infos, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
