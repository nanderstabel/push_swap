/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   deinstalling_machine.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:06:39 by nstabel        #+#    #+#                */
/*   Updated: 2020/01/20 16:06:49 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_event		ps_deinstalling_machine_handler(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	free(machine->commit);
	free(machine->state);
	free(machine->handler);
	return (machine_deinstalled);
}
