/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_instructions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 14:46:16 by nstabel        #+#    #+#                */
/*   Updated: 2020/01/23 14:33:22 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_command	util1(t_command command, short flags)
{
	if (command == SA || command == SB || command == SS)
	{
		flags &= ~FLAG(SA);
		flags &= ~FLAG(SB);
		flags &= ~FLAG(SS);
	}
	else if (command == PA)
		flags &= ~FLAG(PB);
	else if (command == PB)
		flags &= ~FLAG(PA);
	else if (command == RA)
	{
		flags &= ~FLAG(RB);
		flags &= ~FLAG(RRA);
		flags &= ~FLAG(RRR);
	}
	else if (command == RB)
	{
		flags &= ~FLAG(RA);
		flags &= ~FLAG(RRB);
		flags &= ~FLAG(RRR);
	}
	return (flags);
}

static t_command	util2(t_command command, short flags)
{
	if (command == RR)
	{
		flags &= ~FLAG(RRA);
		flags &= ~FLAG(RRB);
		flags &= ~FLAG(RRR);
	}
	else if (command == RRA)
	{
		flags &= ~FLAG(RRB);
		flags &= ~FLAG(RA);
		flags &= ~FLAG(RR);
	}
	else if (command == RRB)
	{
		flags &= ~FLAG(RRA);
		flags &= ~FLAG(RB);
		flags &= ~FLAG(RR);
	}
	else if (command == RRR)
	{
		flags &= ~FLAG(RA);
		flags &= ~FLAG(RB);
		flags &= ~FLAG(RR);
	}
	return (flags);
}

static t_command	util3(t_machine *machine, short flags)
{
	if (machine->size - machine->size_b <= 2)
	{
		flags &= ~FLAG(RA);
		flags &= ~FLAG(RRA);
		flags &= ~FLAG(PB);
		if (machine->size - machine->size_b <= 1)
		{
			flags &= ~FLAG(SA);
			flags &= ~FLAG(SS);
			flags &= ~FLAG(RR);
			flags &= ~FLAG(RRR);
		}
		if (machine->size_b <= 2)
		{
			flags &= ~FLAG(RR);
			flags &= ~FLAG(RRR);
		}
	}
	return (flags);
}

void				set_instructions(t_machine *machine)
{
	t_command	command;
	short		flags;

	command = machine->branch->command;
	flags = machine->branch->flags;
	flags = util1(command, flags);
	flags = util2(command, flags);
	flags = util3(machine, flags);
	if (machine->size_b <= 2)
	{
		flags &= ~FLAG(RB);
		flags &= ~FLAG(RRB);
		if (machine->size_b <= 1)
		{
			flags &= ~FLAG(SB);
			flags &= ~FLAG(SS);
			flags &= ~FLAG(RR);
			flags &= ~FLAG(RRR);
			if (machine->size_b == 0)
				flags &= ~FLAG(PA);
		}
	}
	machine->branch->flags = flags;
}
