/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:21:42 by achahdan          #+#    #+#             */
/*   Updated: 2022/01/04 18:37:16 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
#include "utls/minitalk.h"

unsigned long len = 0;

=======
#include "minitalk.h"
 
unsigned long len = 0;
>>>>>>> d18f7086f3c2ad9f2281df396f275cdacb0cc821
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
		free(c);
		i++;
	}
}
void sig_handler(int sig)
{
	if (sig == SIGUSR1)
		len++;
}

<<<<<<< HEAD
int main(int ac, char **av)
{
	#define COLOR_GREEN	"\x1b[32m"
	signal(SIGUSR1, sig_handler);
=======
int	main(int ac, char **av)
{ 
	signal(SIGUSR1, sig_handler);
	
>>>>>>> d18f7086f3c2ad9f2281df396f275cdacb0cc821
	if (ac == 3)
		send_str(ft_atoi(av[1]), av[2]);
	else
<<<<<<< HEAD
	{
		ft_printf("unvalid args");
		return 0;
	}
	if (len == ft_strlen(av[2]))
		ft_printf(COLOR_GREEN "\nMESSAGE RECIEVED\n\n");
=======
		printf("unvalid args");
	//printf("%d",len);
	if (len == strlen(av[2]))
		printf("got it");
>>>>>>> d18f7086f3c2ad9f2281df396f275cdacb0cc821
	return (0);
}
