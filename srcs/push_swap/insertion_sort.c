/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 19:18:47 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/14 11:51:13 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				found_residue(t_machine *m)
{
	if (m->stack_arr[m->size_b]->position < \
		m->stack_arr[m->size_b]->cln->position)
		insert_print(m, SS);
	else
		insert_print(m, SA);
}

void				sort_residue(t_machine *m)
{
	while ((m->size - m->size_b) > 2)
	{
		while (m->stack_arr[m->size_b + 1]->position == m->size || \
			m->stack_arr[m->size_b + 1]->position == m->size - \
			(m->size % m->chunk_size) + 1)
			insert_print(m, RA);
		insert_print(m, PB);
	}
	if (m->stack_arr[m->size]->position < m->stack_arr[m->size]->cln->position)
		found_residue(m);
	while (m->stack_arr[m->size_b]->chunk == m->stack_arr[m->size_b + 1]->chunk)
	{
		while (!(m->stack_arr[m->size]->position < \
			m->stack_arr[m->size_b]->position && \
			m->stack_arr[m->size_b]->position < \
			m->stack_arr[m->size_b + 1]->position))
			insert_print(m, RA);
		insert_print(m, PA);
	}
	while (m->stack_arr[m->size_b + 1]->position > \
	m->stack_arr[m->size]->position)
		insert_print(m, RA);
}

void				calc_reach(t_machine *machine)
{
	size_t		index;

	index = 1;
	while (index <= machine->size_b)
	{
		if (machine->stack_arr[index]->position == \
			machine->size - machine->size % machine->chunk_size)
			break ;
		++index;
	}
	machine->reach = (machine->size_b - index < index) ? \
		machine->size_b - index : -index;
}

void				empty_b(t_machine *machine)
{
	while (machine->reach > 0)
	{
		insert_print(machine, RB);
		--machine->reach;
	}
	while (machine->reach < 0)
	{
		insert_print(machine, RRB);
		++machine->reach;
	}
	while (machine->size_b)
		insert_print(machine, PA);
}

void				insertion_sort(t_machine *machine)
{
	size_t	chunk;

	machine->chunk_size = (machine->size > 100) ? 40 : 25;
	while (machine->size % machine->chunk_size <= 1 || \
		machine->chunk_size > machine->size)
		--machine->chunk_size;
	create_chunks(machine);
	while (machine->size - machine->size_b >= machine->chunk_size)
	{
		get_score(machine);
		chunk = get_chunk(machine);
		sort_chunk(machine, chunk);
	}
	calc_reach(machine);
	sort_residue(machine);
	empty_b(machine);
	get_score(machine);
	stats_print(machine);
	return ;
}
