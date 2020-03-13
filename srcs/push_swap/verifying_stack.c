/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   verifying_stack.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 14:38:52 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/14 18:24:03 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_event		ps_verifying_stack_handler(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	if (machine->reach == -1 || !machine->root->score)
		return (stack_valid);
	return (stack_invalid);
}
