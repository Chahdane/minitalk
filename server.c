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
char binary_to_char(int *byte)
{
    int i;
    char c;

    i = 0;
    c = 0;
    while (i < 8)
    {
        if (byte[i] == 1)
            c += (byte[i] * power_of_two(i));
        i++;
    }
    return (c);
}
void    sig_handler(int signal)
{
    static int *byte;
    static int  count = 0;
    if (signal == SIGUSR1)
        byte[count] = 1;
    else
        byte[count] = 0;
    count++;
    if (count == 7)
    {
        count = 0;
        printf("%c",binary_to_char(byte));
    }
}
int main()
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
