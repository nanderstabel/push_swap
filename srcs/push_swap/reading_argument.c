/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reading_argument.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 18:22:42 by nstabel        #+#    #+#                */
/*   Updated: 2020/01/18 18:22:47 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_event		ps_reading_argument_handler(void *pointer)
{
	t_machine *machine;

	machine = (t_machine *)pointer;
	if ((int)machine->size == machine->argc)
		return (no_argument);
	++machine->size;
	return (argument_read);
}
