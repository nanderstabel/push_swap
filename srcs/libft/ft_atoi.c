/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 16:20:47 by nstabel        #+#    #+#                */
/*   Updated: 2019/06/14 19:34:52 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoi(const char *str)
{
	long long		i;
	long long		nb;
	long long		sign;

	i = ft_skipspc(str);
	nb = -1;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		++i;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb == -1)
			nb = str[i] - '0';
		else
			nb = (str[i] - '0') + (nb * 10);
		++i;
	}
	return (sign * nb);
}
