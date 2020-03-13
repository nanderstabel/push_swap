/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ilstnew.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 12:23:32 by nstabel        #+#    #+#                */
/*   Updated: 2019/11/29 02:39:05 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ilist	*ft_ilstnew(long long content)
{
	t_ilist	*list;

	list = (t_ilist *)malloc(sizeof(t_ilist));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
