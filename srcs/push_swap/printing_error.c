/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printing_error.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:03:10 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/23 15:50:58 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		free_machine(t_machine *machine)
{
	t_stack		*tmp;
	t_stack		*temp;

	tmp = machine->stack;
	while (tmp)
	{
		temp = tmp;
		tmp = tmp->crn;
		free(temp);
	}
}

t_event			ps_printing_error_handler(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	if (machine->argc)
		ft_putendl("Error");
	free_machine(machine);
	return (error_printed);
}
