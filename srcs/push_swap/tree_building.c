/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_building.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/02 18:24:50 by nstabel        #+#    #+#                */
/*   Updated: 2020/01/20 14:44:36 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ft_newnode(void)
{
	t_stack		*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->index = 0;
	new->value = -1;
	new->position = 0;
	new->distance = -1;
	new->cln = NULL;
	new->crn = NULL;
	new->pln = NULL;
	new->prn = NULL;
	new->self = NULL;
	return (new);
}

t_tree		*ft_newbranch(void)
{
	t_tree		*new;
	t_command	command;

	new = (t_tree *)malloc(sizeof(t_tree));
	command = 0;
	new->flags = DEFAULT;
	new->command = 0;
	new->next = 0;
	new->score = 0;
	new->mode = leaf;
	new->branches = (t_tree **)malloc(sizeof(t_tree *) * (RRR + 1));
	while (command <= RRR)
	{
		new->branches[command] = NULL;
		++command;
	}
	return (new);
}

void		ft_cutbranch(t_tree **branch)
{
	t_command	command;

	command = SA;
	while (command <= RRR)
	{
		if ((*branch)->branches[command])
			ft_cutbranch(&(*branch)->branches[command]);
		++command;
	}
	free((*branch)->branches);
	(*branch)->branches = NULL;
	free(*branch);
	*branch = NULL;
}

int			ft_smaller_value(void *first, void *second)
{
	t_list		*one;
	t_list		*two;
	t_stack		*a;
	t_stack		*b;

	one = (t_list *)first;
	two = (t_list *)second;
	a = (t_stack *)one->content;
	b = (t_stack *)two->content;
	if (a->value < b->value)
		return (1);
	return (0);
}

void		pick_branch(t_machine *machine)
{
	t_command	command;

	command = SA;
	while (command <= RRR)
	{
		if (machine->branch->branches[command])
			machine->root->next = command;
		++command;
	}
	while (command <= RRR)
	{
		if (machine->branch->branches[command])
			ft_cutbranch(&machine->branch->branches[command]);
		++command;
	}
}
