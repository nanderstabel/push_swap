/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 20:56:58 by nstabel        #+#    #+#                */
/*   Updated: 2020/01/07 16:52:44 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			shift_arr(t_machine *machine, char shift)
{
	size_t		index;

	index = 1;
	while (index <= machine->size)
	{
		machine->stack_arr[index]->index -= shift;
		if (!machine->stack_arr[index]->index)
			machine->stack_arr[index]->index = -shift;
		++index;
	}
	machine->size_b += shift;
}

void			commit_pa(void *pointer)
{
	t_machine	*machine;
	t_stack		**arr;

	machine = (t_machine *)pointer;
	arr = machine->stack_arr;
	if (machine->size_b > 1)
	{
		arr[machine->size_b]->cln->crn = \
		arr[machine->size_b]->crn;
		arr[machine->size_b]->crn->cln = \
		arr[machine->size_b]->cln;
	}
	if (machine->size == machine->size_b)
	{
		arr[machine->size_b]->cln = arr[machine->size_b];
		arr[machine->size_b]->crn = arr[machine->size_b];
	}
	else
	{
		arr[machine->size_b]->cln = arr[machine->size];
		arr[machine->size]->crn = arr[machine->size_b];
		arr[machine->size_b]->crn = arr[machine->size_b + 1];
		arr[machine->size_b + 1]->cln = arr[machine->size_b];
	}
	shift_arr(machine, -1);
}

void			commit_pb(void *pointer)
{
	t_machine	*machine;
	t_stack		**arr;

	machine = (t_machine *)pointer;
	arr = machine->stack_arr;
	shift_arr(machine, 1);
	if ((machine->size - machine->size_b))
	{
		arr[machine->size]->crn = arr[machine->size_b + 1];
		arr[machine->size_b + 1]->cln = arr[machine->size];
	}
	if (machine->size_b > 1)
	{
		arr[machine->size_b]->cln = arr[machine->size_b - 1];
		arr[machine->size_b - 1]->crn = arr[machine->size_b];
		arr[machine->size_b]->crn = arr[1];
		arr[1]->cln = arr[machine->size_b];
	}
	else
	{
		arr[machine->size_b]->cln = arr[machine->size_b];
		arr[machine->size_b]->crn = arr[machine->size_b];
	}
}
