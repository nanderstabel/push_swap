/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ilstadd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 18:32:28 by nstabel        #+#    #+#                */
/*   Updated: 2019/11/29 02:38:56 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ilstadd(t_ilist **alst, t_ilist *newlst)
{
	newlst->next = *alst;
	*alst = newlst;
}
