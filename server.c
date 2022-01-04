/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:21:59 by achahdan          #+#    #+#             */
/*   Updated: 2022/01/04 18:42:29 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

char	binary_to_char(int *byte)
{
	int		i;
	char	c;

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

void	sig_handler(int signal)
{
	static int	byte[8];
	static int	count = 0;
	char		c;

	if (signal == SIGUSR1)
	{
		byte[count] = 1;
		count++;
	}
	else if (signal == SIGUSR2)
	{
		byte[count] = 0;
		count++;
	}
	if (count == 8)
	{
		c = binary_to_char(byte);
		write(1, &c, 1);
		count = 0;
	}
}

int	main(void)
{
	printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}
