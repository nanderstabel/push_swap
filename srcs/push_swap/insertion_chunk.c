/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_chunk.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 11:46:05 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/14 12:55:19 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t				get_chunk(t_machine *machine)
{
	size_t		chunks[2 + (machine->size / machine->chunk_size)];
	size_t		index;
	size_t		ret;

	ft_bzero(chunks, sizeof(size_t) * \
		(2 + (machine->size / machine->chunk_size)));
	ret = 0;
	chunks[ret] = SIZE_MAX;
	index = 1;
	while (index <= machine->size)
	{
		while (machine->stack_arr[index]->index < 0)
			++index;
		chunks[machine->stack_arr[index]->chunk] += \
			machine->stack_arr[index]->distance;
		++index;
	}
	index = 1;
	while (index <= (machine->size / machine->chunk_size))
	{
		if (chunks[index] < chunks[ret] && chunks[index])
			ret = index;
		++index;
	}
	return (ret);
}

static void			sort_found(t_machine *m)
{
	insert_print(m, PB);
	if (m->stack_arr[m->size_b]->position > m->biggest)
		m->biggest = m->stack_arr[m->size_b]->position;
	if (m->stack_arr[m->size_b]->position < m->lowest)
		m->lowest = m->stack_arr[m->size_b]->position;
}

void				sort_chunk(t_machine *m, size_t chunk)
{
	t_stack		*up;
	t_stack		*down;
	size_t		count[2];

	set_nodes(m, &up, &down);
	ft_bzero(count, sizeof(size_t) * 2);
	while (count[0] < m->chunk_size)
	{
		if (down->chunk == chunk)
			down_rotate(m, count, down);
		else if (up->chunk == chunk)
			up_rotate(m, count, up);
		else
		{
			++count[1];
			up = up->crn;
			down = down->cln;
		}
		if (!count[1])
		{
			sort_found(m);
			set_nodes(m, &up, &down);
			++count[0];
		}
	}
}

void				create_chunks(t_machine *machine)
{
	size_t	index;
	t_stack	*tmp;

	index = 1;
	while (index <= machine->size)
	{
		tmp = machine->stack_arr[index];
		tmp->chunk = ((tmp->position - 1) / machine->chunk_size) + 1;
		++index;
	}
}
