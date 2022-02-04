#include "minitalk.h"

t_var	g_var;

static void    ft_putchar(char c)
{
    write(1, &c, 1);
}

static void	ft_putnbr(int nb, int c)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10, 0);
		ft_putnbr(n % 10, 0);
	}
    if (c == 1)
        write(1, "\n", 1);                     
}

static void	ft_reset(int pid)
{
    if (pid)
        ft_putnbr(getpid(), 1);
	g_var.c = 0;
	g_var.bit_pos = 0;
}

static void	get_char(int bit)
{
	g_var.c += (bit - MYSIGNAL) << g_var.bit_pos++;
	if (g_var.bit_pos == 8)
	{
        ft_putchar(g_var.c);
        if (!g_var.c)
            ft_putchar('\n');
		ft_reset(0);
	}
}

int	main(void)
{
    ft_reset(1);
	while (1)
	{
		signal(SIGUSR1, get_char);
		signal(SIGUSR2, get_char);
		pause();
	}
	return 0;
}
