#include "minitalk_bonus.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(1, &s[i++], 1);
}

static int     ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		s *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		r = r * 10 + str[i] - 48;
		i++;
	}
	return (r * s);
}

static void	send_bit(int pid, char *s, size_t len)
{
	int		count;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		count = -1;
		while (++count < 8)
		{
			if ((s[i] >> count) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(1000);
		}
		i++;
	}
}

void	recive_message(int i)
{
	if (i == SIGUSR1)
		ft_putstr("(message recived !)\n");
}

int	main(int ac, char **av)
{
	signal(SIGUSR1, recive_message);
	if (ac == 3)
		send_bit(ft_atoi(av[1]), av[2], ft_strlen(av[2]));
	else
		ft_putstr("Usage : ./client <PID>  <STRING> \n");
	return (0);
}
