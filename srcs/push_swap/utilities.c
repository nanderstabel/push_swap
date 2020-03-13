/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 14:13:09 by nstabel        #+#    #+#                */
/*   Updated: 2020/01/20 17:39:10 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		*strcmd(t_command command)
{
	if (command == SA)
		return ("sa");
	if (command == SB)
		return ("sb");
	if (command == SS)
		return ("ss");
	if (command == PA)
		return ("pa");
	if (command == PB)
		return ("pb");
	if (command == RA)
		return ("ra");
	if (command == RB)
		return ("rb");
	if (command == RR)
		return ("rr");
	if (command == RRA)
		return ("rra");
	if (command == RRB)
		return ("rrb");
	if (command == RRR)
		return ("rrr");
	return (NULL);
}

t_command	inverse_of(t_command command)
{
	if (command == SA)
		return (SA);
	if (command == SB)
		return (SB);
	if (command == SS)
		return (SS);
	if (command == PA)
		return (PB);
	if (command == PB)
		return (PA);
	if (command == RA)
		return (RRA);
	if (command == RB)
		return (RRB);
	if (command == RR)
		return (RRR);
	if (command == RRA)
		return (RA);
	if (command == RRB)
		return (RB);
	return (RR);
}

t_command	grow_leaf(t_machine *machine, t_command command)
{
	if (machine->branch->flags & FLAG(command))
	{
		machine->branch->branches[command] = ft_newbranch();
		machine->branch->branches[command]->branches[DOWN] = machine->branch;
		machine->commit[command](machine);
		machine->branch = machine->branch->branches[command];
		machine->branch->command = command;
		get_score(machine);
		if (machine->branch->score == 0)
			machine->reach = 0;
		machine->commit[inverse_of(command)](machine);
		machine->branch = machine->branch->branches[DOWN];
		if (machine->branch->branches[command]->score < machine->branch->score)
			machine->branch->score = machine->branch->branches[command]->score;
	}
	return (command + 1);
}

t_command	commit_command(t_machine *machine, t_command command)
{
	if (machine->branch->branches[command])
	{
		machine->commit[command](machine);
		machine->branch = machine->branch->branches[command];
		find_leaves(machine);
		machine->commit[inverse_of(command)](machine);
		machine->branch = machine->branch->branches[DOWN];
		if (machine->branch->branches[command]->score < machine->branch->score)
			machine->branch->score = machine->branch->branches[command]->score;
	}
	return (command + 1);
}
