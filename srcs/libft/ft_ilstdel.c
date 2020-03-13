/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ilstdel.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 19:54:06 by nstabel        #+#    #+#                */
/*   Updated: 2019/11/29 02:46:07 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ilstdel(t_ilist **alst)
{
	t_ilist	*tmp;

	while (*alst)
	{
		tmp = (*alst)->next;
		ft_ilstdelone(alst);
		*alst = tmp;
	}
	ft_memdel((void **)alst);
}
