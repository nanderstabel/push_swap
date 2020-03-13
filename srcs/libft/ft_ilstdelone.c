/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ilstdelone.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 19:54:53 by nstabel        #+#    #+#                */
/*   Updated: 2019/11/29 02:43:20 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ilstdelone(t_ilist **alst)
{
	(*alst)->content = 0;
	ft_memdel((void **)alst);
}
