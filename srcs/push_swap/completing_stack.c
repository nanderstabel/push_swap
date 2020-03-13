/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   completing_stack.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 18:55:54 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/14 19:20:42 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		single_arg(t_machine *machine, t_list *tmp, int position)
{
	if (!tmp->next)
	{
		machine->stack = ((t_stack *)tmp->content)->self;
		machine->stack->prn = ((t_stack *)tmp->content)->self;
		machine->stack->prn->pln = machine->stack;
		machine->stack->position = position;
		machine->stack_arr[0]->prn = machine->stack;
	}
}

static void		fill_stack(t_machine *machine, t_list *sorted)
{
	t_list		*tmp;
	int			position;

	tmp = sorted;
	position = 1;
	single_arg(machine, tmp, position);
	while (tmp->next)
	{
		machine->stack = ((t_stack *)tmp->content)->self;
		machine->stack->prn = ((t_stack *)tmp->next->content)->self;
		machine->stack->prn->pln = machine->stack;
		machine->stack->position = position;
		if (position == 1)
			machine->stack_arr[0]->prn = machine->stack;
		machine->stack_arr[machine->stack->index] = machine->stack;
		++position;
		tmp = tmp->next;
	}
	machine->stack = ((t_stack *)tmp->content)->self;
	machine->stack->position = position;
	machine->stack_arr[machine->stack->index] = machine->stack;
	machine->stack->prn = ((t_stack *)sorted->content)->self;
	machine->stack->prn->pln = machine->stack;
	machine->stack_arr[1]->cln = machine->stack_arr[machine->size];
	machine->stack_arr[machine->size]->crn = machine->stack_arr[1];
}

t_event			ps_completing_stack_handler(void *pointer)
{
	t_machine	*machine;
	t_list		*sorted;

	machine = (t_machine *)pointer;
	sorted = ft_lstnew(machine->stack, sizeof(t_stack));
	machine->stack = machine->stack->crn;
	while (machine->stack)
	{
		ft_lstapp(&sorted, (ft_lstnew(machine->stack, sizeof(t_stack))));
		machine->stack = machine->stack->crn;
	}
	ft_lstsrt(&sorted, ft_smaller_value);
	machine->stack_arr = (t_stack **)malloc(sizeof(t_stack *) * \
		(machine->size + 1));
	machine->stack_arr[0] = ft_newnode();
	fill_stack(machine, sorted);
	ft_lstdel(&sorted, ft_freezero);
	if (machine->flags & DEFAULT_M)
	{
		if (machine->size > 25)
			machine->flags |= INSERTION_M;
		else
			machine->flags |= STAR_M;
	}
	return (stack_completed);
}
