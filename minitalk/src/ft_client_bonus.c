/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:59:20 by ntome             #+#    #+#             */
/*   Updated: 2025/11/05 17:33:32 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk.h"

void	ft_exit_messages(int message)
{
	if (message == SIGUSR1)
		ft_printf("Message recieved.\n");
	else if (message == SIGUSR2)
		ft_printf("Message lost.\n");
	else if (message == 0)
		write(2, "ARGS ERROR\n", 11);
	else if (message == 1)
		write(2, "PID ERROR\n", 10);
	exit(EXIT_FAILURE);
}

void	ft_send_letter(unsigned char c, int pid)
{
	int	binary_count;
	int	power_count;

	binary_count = 0;
	power_count = 128;
	while (power_count >= 1)
	{
		if (binary_count + power_count > c)
			kill(pid, SIGUSR1);
		else
		{
			binary_count += power_count;
			kill(pid, SIGUSR2);
		}
		power_count /= 2;
		usleep(800);
	}
}

void	ft_send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		ft_send_letter(str[i++], pid);
	ft_send_letter(str[i], pid);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (sign * result);
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	signal_infos;

	signal_infos.sa_handler = &ft_exit_messages;
	sigemptyset(&signal_infos.sa_mask);
	signal_infos.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal_infos, NULL);
	sigaction(SIGUSR2, &signal_infos, NULL);
	if (ac != 3)
		ft_exit_messages(0);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		ft_exit_messages(1);
	ft_send_message(av[2], pid);
	exit(EXIT_SUCCESS);
}
