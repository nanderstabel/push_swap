/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   deleting_stack.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 15:56:46 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/23 15:20:01 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_event		ps_deleting_stack_handler(void *pointer)
{
	t_machine	*machine;
	size_t		i;

	machine = (t_machine *)pointer;
	i = 0;
	while (i <= machine->size)
	{
		free(machine->stack_arr[i]);
		++i;
	}
	free(machine->stack_arr);
	ft_cutbranch(&machine->output);
	return (stack_deleted);
}
