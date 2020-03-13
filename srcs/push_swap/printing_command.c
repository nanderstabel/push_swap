/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printing_command.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 15:55:26 by nstabel        #+#    #+#                */
/*   Updated: 2020/01/20 16:44:23 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_command(t_machine *machine, t_command command)
{
	machine->root->next = command;
	machine->commit[command](machine);
	machine->root = machine->root->branches[command];
	machine->branch = machine->root;
	if (machine->flags & HOR_F)
	{
		get_score(machine);
		ft_printf("%5s:\t\t", strcmd(machine->root->command));
		hor_print(machine);
	}
	else
		ft_printf("%s\n", strcmd(machine->root->command));
	if (machine->flags & COUNT_F)
		ft_printf("\tcount: %i", machine->count);
	ft_putchar(10);
	stats_print(machine);
}

t_event		ps_printing_command_handler(void *pointer)
{
	t_machine	*machine;
	t_command	command;

	machine = (t_machine *)pointer;
	command = SA;
	while (command <= RRR)
	{
		if (machine->root->branches[command])
		{
			print_command(machine, command);
			command = 0;
		}
		++machine->count;
		++command;
	}
	return (command_printed);
}
