/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_rotate.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 11:49:18 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/14 11:55:52 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			set_nodes(t_machine *machine, t_stack **up, t_stack **down)
{
	*up = machine->stack_arr[machine->size_b + 1];
	*down = machine->stack_arr[machine->size_b + 1];
}

int				get_direction(t_machine *machine, t_stack *node)
{
	size_t	chunk;
	size_t	index;

	if (!machine->size_b)
		return (0);
	chunk = node->chunk;
	index = 1;
	if (node->position < machine->lowest)
		while (machine->stack_arr[index]->position != machine->lowest)
			++index;
	else if (node->position > machine->biggest)
	{
		while (machine->stack_arr[index]->position != machine->biggest)
			++index;
		++index;
	}
	else
	{
		while (!(machine->stack_arr[index]->cln->position < node->position && \
			machine->stack_arr[index]->position > node->position))
			++index;
	}
	return ((index - 1 < machine->size_b + 1 - index) ? -(index - 1) : \
		machine->size_b + 1 - index);
}

void			up_rotate(t_machine *machine, size_t *count, t_stack *up)
{
	int		direction;

	direction = get_direction(machine, up);
	while (count[1])
	{
		if (direction > 0)
		{
			insert_print(machine, RR);
			--direction;
		}
		else
			insert_print(machine, RA);
		--count[1];
	}
	while (direction < 0)
	{
		insert_print(machine, RRB);
		++direction;
	}
	while (direction > 0)
	{
		insert_print(machine, RB);
		--direction;
	}
}

void			down_rotate(t_machine *machine, size_t *count, t_stack *down)
{
	int		direction;

	direction = get_direction(machine, down);
	while (count[1])
	{
		if (direction < 0)
		{
			insert_print(machine, RRR);
			++direction;
		}
		else
			insert_print(machine, RRA);
		--count[1];
	}
	while (direction < 0)
	{
		insert_print(machine, RRB);
		++direction;
	}
	while (direction > 0)
	{
		insert_print(machine, RB);
		--direction;
	}
}
