/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distance.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 12:04:36 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/14 19:21:06 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	d_ab(int cur, int neigh, int a, int b)
{
	if (cur == a - cur)
	{
		if (neigh < b - neigh)
			return ((cur > neigh) ? cur : neigh);
		return ((cur > b - neigh) ? cur : b - neigh);
	}
	if (neigh == b - neigh)
	{
		if (cur < a - cur)
			return ((neigh > cur) ? neigh : cur);
		return ((neigh > a - cur) ? neigh : a - cur);
	}
	if (cur < a - cur)
	{
		if (neigh <= b - neigh)
			return ((cur > neigh) ? cur : neigh);
		if (neigh - cur < b - neigh)
			return ((neigh - cur) + cur);
		return (b - neigh + cur);
	}
	if (neigh >= b - neigh)
		return ((a - cur > b - neigh) ? a - cur : b - neigh);
	if (b - (neigh + (a - cur)) < neigh)
		return (b - (neigh + (a - cur)) + (a - cur));
	return (a - cur + neigh);
}

static size_t	calc_distance(int fir, int sec, int size)
{
	if (fir + 1 == sec || (fir == size && sec == 1))
		return (0);
	if (fir < sec)
	{
		if (fir * 2 > size)
			return (size - fir + 1);
		if (fir + 2 == sec)
			return (fir);
		if (sec - fir - 1 < size + 1 - sec)
			return ((sec - 1 < size - fir + 1) ? sec - 1 : size - fir + 1);
		return ((size + 1 - sec + fir < size - fir + 1) ? \
			size + 1 - sec + fir : size - fir + 1);
	}
	if (fir == size && sec - 1 <= size / 2)
		return (sec - 1);
	if ((size + 1) / 2 < sec)
		return (size - sec + 2);
	if (sec + 1 == fir)
		return (sec);
	if (fir - sec < size - fir)
		return ((fir < size - sec + 2) ? fir : size - sec + 2);
	return ((sec + size - fir < size - sec + 2) ? \
		sec + size - fir : size - sec + 2);
}

static void		star_loop(t_stack *ar, size_t s, size_t sb, size_t *d)
{
	if (ar->index > 0 && ar->prn->index > 0)
		*d = calc_distance(ar->index, ar->prn->index, s - sb);
	else if (ar->index < 0 && ar->prn->index < 0)
		*d = calc_distance(ft_abs(ar->prn->index), ft_abs(ar->index), sb);
	else if (ar->index < 0 && ar->prn->index > 0)
		*d = d_ab(ft_abs(ar->index) - 1, ar->prn->index - 1, sb, s - sb);
	else
		*d = d_ab(ar->index, ft_abs(ar->prn->index) - 1, s - sb, sb) + 1;
}

void			loop_stack(t_machine *machine)
{
	t_stack		*ar;
	size_t		index;
	size_t		s;
	size_t		sb;
	size_t		*d;

	machine->branch->score = 0;
	s = machine->size;
	sb = machine->size_b;
	index = 1;
	while (index <= s)
	{
		ar = machine->stack_arr[index];
		d = &ar->distance;
		if (machine->flags & INSERTION_M)
			*d = calc_distance(ar->index, 2, s - sb);
		else
			star_loop(ar, s, sb, d);
		machine->branch->score += *d;
		++index;
	}
}

void			get_score(t_machine *machine)
{
	loop_stack(machine);
	if (machine->flags & INSERTION_M)
		return ;
	if (machine->stack_arr[0]->prn->index < 0)
	{
		machine->branch->score += d_ab(machine->stack_arr[0]->prn->index, 1, \
		machine->size_b, machine->size - machine->size_b);
	}
	else
	{
		machine->branch->score += (machine->stack_arr[0]->prn->index - 1 < \
		(int)(machine->size - machine->size_b + 1) - \
		machine->stack_arr[0]->prn->index) ? machine->stack_arr[0]->prn->index \
		- 1 : (machine->size - machine->size_b + 1) - \
		machine->stack_arr[0]->prn->index;
	}
	machine->branch->score += machine->size_b;
}
