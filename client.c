#include <stdio.h>
#include <stdlib.h>
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

void	send_str(char *str, int pid)
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
		}
		i++;
	}
}

int	main()
{
	send_str("hello");
}
