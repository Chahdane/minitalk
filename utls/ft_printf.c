/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:44:09 by achahdan          #+#    #+#             */
/*   Updated: 2021/11/22 17:06:47 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	check_and_print(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	va_start(args, str);
	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += check_and_print(str[i + 1], args) - 2;
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (ret + i);
}
