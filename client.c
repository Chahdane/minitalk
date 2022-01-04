/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:21:42 by achahdan          #+#    #+#             */
/*   Updated: 2022/01/04 15:21:43 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

char	*char_to_binary(char c)
{
	char	*ret;
	int		i;

	i = 7;
	ret = malloc(sizeof(char) * 8);
	while (i >= 0)
	{
		if (c % 2 == 0)
			ret[i] = '0';
		else
			ret[i] = '1';
		c /= 2;
		i--;
	}
	return (ret);
}

void	send_str(int pid, char *str)
{
	int		i;
	char	*c;
	int		j;

	i = 0;
	while (str[i])
	{
		c = char_to_binary(str[i]);
		j = 0;
		while (c[j])
		{
			if (c[j] == '1')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(100);
		}
		i++;
	}
}
int	main(int ac, char** av)
{
	if (ac == 3)
		send_str(atoi(av[1]), av[2]);
	else 
		printf("unvalid args");
	return (0);
}
