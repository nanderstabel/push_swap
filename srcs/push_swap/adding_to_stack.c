/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adding_to_stack.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 18:55:11 by nstabel        #+#    #+#                */
/*   Updated: 2020/01/18 18:55:17 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_event		ps_adding_to_stack_handler(void *pointer)
{
	t_machine	*machine;
	t_stack		*add;
	t_stack		*last;

	machine = (t_machine *)pointer;
	add = ft_newnode();
	last = machine->stack;
	if (machine->stack)
	{
		while (last->crn)
			last = last->crn;
		last->crn = add;
	}
	else
		machine->stack = add;
	add->index = (int)machine->size;
	add->value = (int)machine->argument_holder;
	add->cln = last;
	add->self = add;
	return (added_to_stack);
}
