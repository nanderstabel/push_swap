/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   verifying_argument.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 18:23:52 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/23 16:59:01 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t				get_length(t_machine *machine)
{
	size_t		length;

	length = 0;
	while (ft_isdigit(**machine->argv))
	{
		++(*machine->argv);
		++length;
	}
	return (length);
}

t_event				ps_verifying_argument_handler(void *pointer)
{
	t_machine	*machine;
	t_stack		*searching;
	size_t		length;

	machine = (t_machine *)pointer;
	machine->argument_holder = ft_atoi(*machine->argv);
	if (**machine->argv == '-' || **machine->argv == '+')
		++(*machine->argv);
	length = get_length(machine);
	if (machine->argument_holder > __INT_MAX__ || length > 10 || \
			**machine->argv != 0 || machine->argument_holder < __INT_MIN__)
		return (argument_invalid);
	if (machine->stack)
	{
		searching = machine->stack;
		while (searching)
		{
			if ((int)machine->argument_holder == searching->value)
				return (argument_invalid);
			searching = searching->crn;
		}
	}
	++machine->argv;
	return (argument_valid);
}
