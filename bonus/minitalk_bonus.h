/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:28:58 by abettach          #+#    #+#             */
/*   Updated: 2022/02/07 19:29:20 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <unistd.h>
# include <stdlib.h> 
# include <signal.h>
# define MYSIGNAL 30

typedef struct s_var
{
	char	c;
	size_t	bit_pos;
}	t_var;
t_var	g_var;

size_t	ft_strlen(const char *s);

#endif
