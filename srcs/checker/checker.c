/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 13:32:38 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/23 16:24:01 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		install_handlers(t_machine **machine)
{
	(*machine)->handler = (t_event_handler *)malloc(sizeof(t_event_handler) * \
							(deinstalling_machine + 1));
	(*machine)->handler[receiving_input] = ps_receiving_input_handler;
	(*machine)->handler[reading_argument] = ps_reading_argument_handler;
	(*machine)->handler[verifying_argument] = ps_verifying_argument_handler;
	(*machine)->handler[adding_to_stack] = ps_adding_to_stack_handler;
	(*machine)->handler[completing_stack] = ps_completing_stack_handler;
	(*machine)->handler[planting_tree] = ps_planting_tree_handler;
	(*machine)->handler[deleting_stack] = ps_deleting_stack_handler;
	(*machine)->handler[printing_error] = ps_printing_error_handler;
	(*machine)->handler[checking] = ch_checker_handler;
	(*machine)->handler[deinstalling_machine] = ps_deinstalling_machine_handler;
}

static void		install_states(t_machine **machine)
{
	(*machine)->state = (t_state *)malloc(sizeof(t_state) * \
							machine_deinstalled);
	(*machine)->state[machine_installed] = receiving_input;
	(*machine)->state[input_received] = reading_argument;
	(*machine)->state[no_input] = printing_error;
	(*machine)->state[argument_read] = verifying_argument;
	(*machine)->state[no_argument] = completing_stack;
	(*machine)->state[argument_valid] = adding_to_stack;
	(*machine)->state[argument_invalid] = printing_error;
	(*machine)->state[added_to_stack] = reading_argument;
	(*machine)->state[stack_completed] = planting_tree;
	(*machine)->state[tree_planted] = checking;
	(*machine)->state[checked] = deleting_stack;
	(*machine)->state[stack_deleted] = deinstalling_machine;
	(*machine)->state[error_printed] = deinstalling_machine;
}

static void		install_operators(t_machine **machine)
{
	(*machine)->commit = (t_commit *)malloc(sizeof(t_commit) * RRR);
	(*machine)->commit[0] = NULL;
	(*machine)->commit[SA] = commit_sa;
	(*machine)->commit[SB] = commit_sb;
	(*machine)->commit[SS] = commit_ss;
	(*machine)->commit[PA] = commit_pa;
	(*machine)->commit[PB] = commit_pb;
	(*machine)->commit[RA] = commit_ra;
	(*machine)->commit[RB] = commit_rb;
	(*machine)->commit[RR] = commit_rr;
	(*machine)->commit[RRA] = commit_rra;
	(*machine)->commit[RRB] = commit_rrb;
	(*machine)->commit[RRR] = commit_rrr;
}

static void		setup(t_machine **machine)
{
	*machine = (t_machine *)malloc(sizeof(t_machine));
	install_states(machine);
	install_handlers(machine);
	install_operators(machine);
	(*machine)->flags = DEFAULT_M;
	(*machine)->precision = 7;
	(*machine)->count = 1;
	(*machine)->size = 0;
	(*machine)->size_b = 0;
	(*machine)->stack = NULL;
	(*machine)->stack_arr = NULL;
	(*machine)->output = NULL;
	(*machine)->root = NULL;
	(*machine)->branch = NULL;
	(*machine)->event = machine_installed;
	(*machine)->lowest = SIZE_MAX;
	(*machine)->biggest = 0;
}

int				main(int argc, char **argv)
{
	t_machine	*machine;

	setup(&machine);
	machine->argc = argc - 1;
	machine->argv = argv + 1;
	while (machine->event != machine_deinstalled)
	{
		machine->flags &= ~STAR_M;
		machine->flags &= ~INSERTION_M;
		machine->event = \
		(*machine->handler[machine->state[machine->event]])(machine);
	}
	free(machine);
	machine = NULL;
	return (0);
}
