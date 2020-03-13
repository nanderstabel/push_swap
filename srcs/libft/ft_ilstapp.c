/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ilstapp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 11:45:02 by nstabel        #+#    #+#                */
/*   Updated: 2019/11/29 02:40:00 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ilstapp(t_ilist **alst, t_ilist *newlst)
{
	t_ilist	*tmp;

	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newlst;
}
