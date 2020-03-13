/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   receiving_input.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 18:18:51 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/14 18:01:56 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		set_mode(t_machine *machine)
{
	*machine->argv += 5;
	machine->flags &= ~STAR_M;
	machine->flags &= ~INSERTION_M;
	machine->flags &= ~DEFAULT_M;
	if (ft_strequ(*machine->argv, "=star"))
		machine->flags |= STAR_M;
	else if (ft_strequ(*machine->argv, "=insertion"))
		machine->flags |= INSERTION_M;
	else if (ft_strequ(*machine->argv, "=default"))
		machine->flags |= DEFAULT_M;
	else
	{
		machine->flags = ERROR;
		return (0);
	}
	return (1);
}

static int		set_precision(t_machine *machine)
{
	*machine->argv += 11;
	if (!ft_isdigit(**machine->argv))
	{
		machine->flags = ERROR;
		return (0);
	}
	machine->precision = ft_atoi(*machine->argv);
	return (1);
}

static void		set_flags(t_machine *machine)
{
	if (**machine->argv == 'c')
		machine->flags |= COUNT_F;
	else if (**machine->argv == 'h')
		machine->flags |= HOR_F;
	else if (**machine->argv == 's')
		machine->flags |= STATS_F;
	else if (**machine->argv == 'v')
		machine->flags |= VERT_F;
}

static int		set_options(t_machine *machine)
{
	if (!machine->argc || **machine->argv != '-' || \
		ft_isdigit(*(*machine->argv + 1)))
		return (0);
	++(*machine->argv);
	if (ft_strnequ(*machine->argv, "-mode", 5))
		return (set_mode(machine));
	if (ft_strnequ(*machine->argv, "-precision=", 11))
		return (set_precision(machine));
	if (!**machine->argv)
	{
		machine->flags = ERROR;
		return (0);
	}
	while (**machine->argv)
	{
		if (!ft_strchr(FLAGS, **machine->argv))
		{
			machine->flags = ERROR;
			return (0);
		}
		else
			set_flags(machine);
		++(*machine->argv);
	}
	return (1);
}

t_event			ps_receiving_input_handler(void *pointer)
{
	t_machine	*machine;

	machine = (t_machine *)pointer;
	while (set_options(machine))
	{
		++machine->argv;
		--machine->argc;
	}
	if (machine->argc == 0 || machine->flags == ERROR)
		return (no_input);
	return (input_received);
}
