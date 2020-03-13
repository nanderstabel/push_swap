/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 15:30:51 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/23 17:00:36 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define __INT_MIN__	-2147483648
# define FLAG(command)	(1 << command)
# define DEFAULT		0xFFE
# define ERROR			0xFF
# define ILL_OPT		"push_swap: illegal option --"
# define FLAGS			"chsv"
# define COUNT_F		(1 << 0)
# define HOR_F			(1 << 1)
# define STATS_F		(1 << 2)
# define VERT_F			(1 << 3)
# define STAR_M			(1 << 4)
# define INSERTION_M	(1 << 5)
# define DEFAULT_M		(1 << 6)

# define HANDLER		*machine->handler

typedef enum
{
	root,
	branch,
	leaf
}	t_mode;

typedef enum
{
	DOWN,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_command;

typedef enum
{
	receiving_input,
	reading_argument,
	verifying_argument,
	adding_to_stack,
	completing_stack,
	planting_tree,
	verifying_stack,
	growing_leaves,
	printing_command,
	deleting_stack,
	printing_error,
	checking,
	deinstalling_machine
}	t_state;

typedef enum
{
	machine_installed,
	input_received,
	no_input,
	argument_read,
	no_argument,
	argument_valid,
	argument_invalid,
	added_to_stack,
	stack_completed,
	tree_planted,
	stack_valid,
	stack_invalid,
	leaves_grew,
	command_printed,
	stack_deleted,
	error_printed,
	checked,
	machine_deinstalled
}	t_event;

typedef t_event			(*t_event_handler)(void *);
typedef void			(*t_commit)(void *);

typedef struct			s_stack
{
	int					index;
	int					value;
	size_t				position;
	size_t				distance;
	size_t				chunk;
	struct s_stack		*cln;
	struct s_stack		*crn;
	struct s_stack		*pln;
	struct s_stack		*prn;
	struct s_stack		*self;
}						t_stack;

typedef struct			s_tree
{
	short				flags;
	t_command			command;
	t_command			next;
	size_t				score;
	t_mode				mode;
	struct s_tree		**branches;
}						t_tree;

typedef struct			s_machine
{
	unsigned char		flags;
	char				precision;
	int					count;
	t_state				*state;
	t_event				event;
	t_event_handler		*handler;
	int					argc;
	char				**argv;
	size_t				size;
	size_t				size_b;
	long long			argument_holder;
	char				*instruction_holder;
	t_stack				*stack;
	t_stack				**stack_arr;
	t_commit			*commit;
	int					reach;
	t_tree				*root;
	t_tree				*branch;
	t_tree				*output;
	size_t				lowest;
	size_t				biggest;
	size_t				chunk_size;
}						t_machine;

t_event					ps_receiving_input_handler(void *pointer);
t_event					ps_reading_argument_handler(void *pointer);
t_event					ps_verifying_argument_handler(void *pointer);
t_event					ps_adding_to_stack_handler(void *pointer);
t_event					ps_completing_stack_handler(void *pointer);
t_event					ps_planting_tree_handler(void *pointer);
t_event					ps_verifying_stack_handler(void *pointer);
t_event					ps_growing_leaves_handler(void *pointer);
t_event					ps_printing_command_handler(void *pointer);
t_event					ps_deleting_stack_handler(void *pointer);
t_event					ps_printing_error_handler(void *pointer);
t_event					ps_deinstalling_machine_handler(void *pointer);
int						ft_smaller_value(void *first, void *second);
t_stack					*ft_newnode(void);
t_tree					*ft_newbranch(void);
void					ft_cutbranch(t_tree **branch);
void					pick_branch(t_machine *machine);
void					find_leaves(void *pointer);
void					commit_sa(void *pointer);
void					commit_sb(void *pointer);
void					commit_ss(void *pointer);
void					commit_pa(void *pointer);
void					commit_pb(void *pointer);
void					commit_ra(void *pointer);
void					commit_rb(void *pointer);
void					commit_rr(void *pointer);
void					commit_rra(void *pointer);
void					commit_rrb(void *pointer);
void					commit_rrr(void *pointer);
void					insert_print(t_machine *machine, t_command command);
void					stats_print(t_machine *machine);
void					hor_print(t_machine *machine);
void					get_score(t_machine *machine);
char					*strcmd(t_command command);
t_command				inverse_of(t_command command);
void					set_instructions(t_machine *pointer);
t_command				commit_command(t_machine *machine, t_command command);
t_command				grow_leaf(t_machine *machine, t_command command);
void					insertion_sort(t_machine *machine);
void					set_nodes(t_machine *machine, t_stack **up, \
							t_stack **down);
int						get_direction(t_machine *machine, t_stack *node);
void					up_rotate(t_machine *machine, size_t *count, \
							t_stack *up);
void					down_rotate(t_machine *machine, size_t *count, \
							t_stack *down);
size_t					get_chunk(t_machine *machine);
void					sort_chunk(t_machine *m, size_t chunk);
void					create_chunks(t_machine *machine);
void					loop_stack(t_machine *machine);
t_event					ch_checker_handler(void *pointer);

#endif
