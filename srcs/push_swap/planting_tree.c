/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   planting_tree.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 14:21:41 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/14 19:22:11 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_event		ps_planting_tree_handler(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	machine->root = ft_newbranch();
	machine->branch = machine->root;
	machine->output = machine->root;
	if (machine->flags & INSERTION_M)
	{
		insertion_sort(machine);
		return (command_printed);
	}
	get_score(machine);
	if (machine->flags & HOR_F)
	{
		ft_printf("start:\t\t");
		hor_print(machine);
		ft_putchar(10);
	}
	stats_print(machine);
	return (tree_planted);
}
