/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:20:56 by abettach          #+#    #+#             */
/*   Updated: 2022/02/07 19:21:19 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h> 
# include <signal.h>
# include <stdio.h>
# define MYSIGNAL 30

typedef struct s_var
{
	char	c;
	size_t	bit_pos;
}	t_var;
t_var	g_var;

#endif