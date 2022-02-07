/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:21:44 by abettach          #+#    #+#             */
/*   Updated: 2022/02/07 19:22:47 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_putchar(char c)
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

static void	get_char(int bit, siginfo_t *info, void *context)
{
	(void)context;
	g_var.c += (bit - MYSIGNAL) << g_var.bit_pos++;
	if (g_var.bit_pos == 8)
	{
		ft_putchar(g_var.c);
		if (!g_var.c)
		{
			kill(info->si_pid, SIGUSR1);
			ft_putchar('\n');
		}
		ft_reset(0);
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = get_char;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	ft_reset(1);
	while (1)
	{
		sigaction(SIGUSR2, &action, NULL);
		sigaction(SIGUSR1, &action, NULL);
		pause();
	}
}
