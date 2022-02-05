#ifndef _MINITALK_BONUS_H
#define _MINITALK_BONUS_H
# include <unistd.h>
# include <stdlib.h> 
# include <signal.h>
#define MYSIGNAL 30

typedef struct s_var
{
	char	c;
	size_t	bit_pos;
}	t_var;
t_var	g_var;

#endif