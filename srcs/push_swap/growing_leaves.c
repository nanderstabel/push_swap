/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   growing_leaves.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 15:55:03 by nstabel        #+#    #+#                */
/*   Updated: 2020/01/23 12:59:00 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		grow_leaves(void *pointer)
{
	t_machine	*machine;
	t_command	command;

	machine = (t_machine *)pointer;
	command = SA;
	if (machine->branch->mode != root)
		machine->branch->mode = branch;
	machine->branch->score = __INT_MAX__;
	set_instructions(machine);
	while (command <= RRR)
		command = grow_leaf(machine, command);
}

void		cut_branches(void *pointer)
{
	t_machine	*machine;
	t_command	command;

	machine = (t_machine *)pointer;
	command = SA;
	while (command <= RRR)
	{
		if (machine->branch->branches[command])
		{
			if (machine->branch->branches[command]->score > \
				machine->branch->score)
			{
				ft_cutbranch(&machine->branch->branches[command]);
				machine->branch->branches[command] = NULL;
			}
			else if (machine->branch->branches[command]->score == \
				machine->branch->score)
				machine->branch->next = command;
		}
		++command;
	}
}

void		find_leaves(void *pointer)
{
	t_machine	*machine;
	t_command	command;

	machine = (t_machine *)pointer;
	command = SA;
	if (machine->branch->mode != leaf)
	{
		while (command <= RRR)
			command = commit_command(machine, command);
	}
	else
		grow_leaves(machine);
	if (machine->reach <= 1)
		cut_branches(machine);
}

void		tree_climbing(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	while (machine->root->next)
	{
		machine->branch = machine->root;
		pick_branch(machine);
		machine->commit[machine->root->next](machine);
		if (machine->flags & HOR_F)
		{
			get_score(machine);
			ft_printf("%5s:\t\t", strcmd(machine->root->next));
			hor_print(machine);
		}
		else
			ft_printf("%s", strcmd(machine->root->next));
		if (machine->flags & COUNT_F)
			ft_printf("\tcount: %i", machine->count);
		ft_putchar(10);
		stats_print(machine);
		machine->root = machine->root->branches[machine->root->next];
		++machine->count;
	}
	machine->branch = machine->root;
}

t_event		ps_growing_leaves_handler(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	machine->reach = machine->precision;
	while (machine->reach > 0)
	{
		find_leaves(machine);
		--machine->reach;
	}
	tree_climbing(machine);
	return (leaves_grew);
}
