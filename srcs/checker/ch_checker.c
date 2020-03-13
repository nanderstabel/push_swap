/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ch_checker.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 13:55:34 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/15 14:50:38 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_command				cmdstr(char *str)
{
	if (!ft_memcmp("sa", str, 3))
		return (SA);
	else if (!ft_memcmp("sb", str, 3))
		return (SB);
	else if (!ft_memcmp("ss", str, 3))
		return (SS);
	else if (!ft_memcmp("pa", str, 3))
		return (PA);
	else if (!ft_memcmp("pb", str, 3))
		return (PB);
	else if (!ft_memcmp("ra", str, 3))
		return (RA);
	else if (!ft_memcmp("rb", str, 3))
		return (RB);
	else if (!ft_memcmp("rr", str, 3))
		return (RR);
	else if (!ft_memcmp("rra", str, 4))
		return (RRA);
	else if (!ft_memcmp("rrb", str, 4))
		return (RRB);
	else if (!ft_memcmp("rrr", str, 4))
		return (RRR);
	ft_putendl("Error");
	return (DOWN);
}

t_event					ch_checker_handler(void *pointer)
{
	t_machine	*machine;
	t_command	command;

	machine = (t_machine *)pointer;
	while (get_next_line(0, &machine->instruction_holder) != 0)
	{
		command = cmdstr(machine->instruction_holder);
		free(machine->instruction_holder);
		if (!command)
			return (checked);
		if (!((command == PA && !machine->size_b) || \
			(command == PB && !(machine->size - machine->size_b)) || \
			((command == SA || command == SS) && machine->size - \
			machine->size_b < 2) || ((command == SB || command == SS) && \
			machine->size_b < 2)))
			machine->commit[command](machine);
	}
	loop_stack(machine);
	stats_print(machine);
	if (!machine->root->score && machine->stack_arr[1]->position == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (checked);
}
