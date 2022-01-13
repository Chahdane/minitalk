/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:21:42 by achahdan          #+#    #+#             */
/*   Updated: 2022/01/06 15:32:23 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utls/minitalk.h"

unsigned long	g_len = 0;

void	char_to_binary(char c, char *ret)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (c % 2 == 0)
			ret[i] = '0';
		else
			ret[i] = '1';
		c /= 2;
		i--;
	}
}

void	send_str(int pid, char *str)
{
	int		i;
	char	*c;
	int		j;

	i = 0;
	while (str[i])
	{
		c = malloc(sizeof(char) * 8);
		if (!c)
			return ;
		char_to_binary(str[i], c);
		j = 0;
		while (c[j])
		{
			if (c[j] == '1')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(1000);
		}
		free(c);
		i++;
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_len++;
}

int	main(int ac, char **av)
{
	signal(SIGUSR1, sig_handler);
	if (ac == 3)
		send_str(ft_atoi(av[1]), av[2]);
	else
	{
		ft_printf("Unvalid args");
		return (0);
	}
	if (g_len == ft_strlen(av[2]))
		ft_printf("\nMESSAGE RECIEVED\n\n");
	return (0);
}
