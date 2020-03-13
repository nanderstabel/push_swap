/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 13:51:31 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/14 16:02:21 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			insert_print(t_machine *machine, t_command command)
{
	machine->commit[command](machine);
	++machine->count;
	ft_printf("%s", strcmd(command));
	if (machine->flags & COUNT_F)
		ft_printf("\tcount: %i", machine->count);
	ft_putchar(10);
}

void			hor_print(t_machine *machine)
{
	size_t		index;

	index = 1;
	ft_printf("B|   ");
	while (index <= machine->size)
	{
		if (machine->stack_arr[index]->index == 1)
			ft_putstr(" | ");
		else
			ft_putstr("");
		if (machine->stack_arr[index]->distance == 0)
		{
			write(1, "\x1B[1m", 4);
			write(1, "\x1B[32m", 5);
		}
		else if (machine->stack_arr[index]->pln->distance == 0)
		{
			write(1, "\x1B[33m", 5);
		}
		ft_printf("[%2i]", machine->stack_arr[index]->value);
		ft_printf("{eoc}");
		++index;
	}
	ft_printf("   |A");
	ft_printf("\t--> score: %i", machine->branch->score);
}

static void		print_line(void)
{
	char		line[249];

	line[248] = 0;
	ft_memset(line, '-', 248);
	ft_printf("%s\n", line);
}

void			stats_print(t_machine *machine)
{
	size_t	index;
	t_stack	**print;

	index = 1;
	print = machine->stack_arr;
	if ((machine->flags & STATS_F) != STATS_F)
		return ;
	if (machine->flags & STAR_M)
		get_score(machine);
	ft_printf("Stack A size: %i\nStack B size: %i\n", machine->size - \
		machine->size_b, machine->size_b);
	print_line();
	while (index <= machine->size)
	{
		ft_printf("address: %p\tself: %p\tvalue: %-12iindex: %i\tposition: "
			"%i\tdistance: %i\tcur_l_add: %p   \tcur_r_add: %p   "
			"\tproj_l_add: %p   \tproj_r_add: %p\tchunk: %i\n",
			print[index], print[index]->self, print[index]->value,
			print[index]->index, print[index]->position, print[index]->distance,
			print[index]->cln, print[index]->crn, print[index]->pln,
			print[index]->prn, print[index]->chunk);
		++index;
	}
	print_line();
	ft_putendl("\n");
}
