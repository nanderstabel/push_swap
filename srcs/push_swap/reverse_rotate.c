/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 20:57:23 by nstabel        #+#    #+#                */
/*   Updated: 2020/01/07 16:52:44 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			commit_rra(void *pointer)
{
	t_machine	*machine;
	size_t		index;

	machine = (t_machine *)pointer;
	index = machine->size_b + 1;
	while (index <= machine->size)
	{
		machine->stack_arr[index] = machine->stack_arr[index]->cln;
		machine->stack_arr[index]->index = index - machine->size_b;
		++index;
	}
}

void			commit_rrb(void *pointer)
{
	t_machine	*machine;
	size_t		index;

	machine = (t_machine *)pointer;
	index = 0;
	while (index < machine->size_b)
	{
		machine->stack_arr[machine->size_b - index] = \
		machine->stack_arr[machine->size_b - index]->crn;
		machine->stack_arr[machine->size_b - index]->index = -(index + 1);
		++index;
	}
}

void			commit_rrr(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	commit_rra(machine);
	commit_rrb(machine);
}
