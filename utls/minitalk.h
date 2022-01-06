/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:22:13 by achahdan          #+#    #+#             */
/*   Updated: 2022/01/06 15:32:41 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_itoa(int n);
int		ft_atoi(char *str);

#endif
