/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 20:57:50 by nstabel        #+#    #+#                */
/*   Updated: 2020/01/07 16:52:44 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			commit_sa(void *pointer)
{
	t_machine	*machine;
	t_stack		**arr;

	machine = (t_machine *)pointer;
	arr = machine->stack_arr;
	if (machine->size - machine->size_b == 2)
	{
		commit_ra(machine);
		return ;
	}
	arr[machine->size_b + 2]->crn->cln = \
		arr[machine->size_b + 1];
	arr[machine->size_b + 2]->cln = arr[machine->size];
	arr[machine->size_b + 1]->cln = arr[machine->size_b + 2];
	arr[machine->size]->crn = arr[machine->size_b + 2];
	arr[machine->size_b + 1]->crn = \
		arr[machine->size_b + 2]->crn;
	arr[machine->size_b + 2]->crn = arr[machine->size_b + 1];
	arr[machine->size_b + 1] = arr[machine->size]->crn;
	arr[machine->size_b + 2] = arr[machine->size_b + 1]->crn;
	arr[machine->size_b + 1]->index = 1;
	arr[machine->size_b + 2]->index = 2;
}

void			commit_sb(void *pointer)
{
	t_machine	*machine;
	t_stack		**arr;

	machine = (t_machine *)pointer;
	arr = machine->stack_arr;
	if (machine->size_b == 2)
	{
		commit_rb(machine);
		return ;
	}
	arr[machine->size_b - 1]->cln->crn = \
		arr[machine->size_b];
	arr[machine->size_b - 1]->crn = arr[1];
	arr[machine->size_b]->crn = arr[machine->size_b - 1];
	arr[1]->cln = arr[machine->size_b - 1];
	arr[machine->size_b]->cln = \
		arr[machine->size_b - 1]->cln;
	arr[machine->size_b - 1]->cln = arr[machine->size_b];
	arr[machine->size_b] = arr[1]->cln;
	arr[machine->size_b - 1] = arr[machine->size_b]->cln;
	arr[machine->size_b]->index = -1;
	arr[machine->size_b - 1]->index = -2;
}

void			commit_ss(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	commit_sa(machine);
	commit_sb(machine);
}
