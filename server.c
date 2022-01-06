/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:21:59 by achahdan          #+#    #+#             */
/*   Updated: 2022/01/06 15:31:48 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utls/minitalk.h"

int	power_of_two(int pow)
{
	int	res;

	res = 1;
	while (pow > 0)
	{
		res = res * 2;
		pow--;
	}
	return (res);
}

int	binary_to_char(int *byte)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		if (byte[i] == 1)
			c += (byte[i] * power_of_two(7 - i));
		i++;
	}
	return (c);
}

void	sig_handler(int signal, siginfo_t *info)
{
	static int	byte[8];
	static int	count = 0;
	int			c;

	if (signal == SIGUSR1)
		byte[count++] = 1;
	else if (signal == SIGUSR2)
		byte[count++] = 0;
	if (count == 8)
	{
		c = binary_to_char(byte);
		ft_printf("%c", c);
		kill(info->si_pid, SIGUSR1);
		count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = (void *)sig_handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
