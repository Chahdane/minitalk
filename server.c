#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void    *sig_handler(int signal)
{
    static char *byte;
    static int  count;

    if (signal == SIGUSR1)
        byte[count] = '1';
    else
        byte[count] = '0';
    count++;
    if (count == 8)
    {

    }
}
int main()
{
	printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
	}
	return (0);
}
