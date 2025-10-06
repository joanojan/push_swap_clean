/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvila-va <jvila-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:36:30 by jvila-va          #+#    #+#             */
/*   Updated: 2025/10/03 15:21:51 by jvila-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>

/**
 *	The Stack is a circular doubly linked list with dummy head,
 *	the sentine, pointing to itself if the stack is empty.
 *	This is to simplify the code and cost of all operations: O(1).
 *	Normalized values: value = final position in the stack.
 */

typedef enum e_op_code
{
	OP_RR,
	OP_RRR,
	OP_RA_RRB,
	OP_RB_RRA
}					t_op_code;

typedef struct s_move_plan
{
	int				cost;
	int				shared;
	int				residual_a;
	int				residual_b;
	t_op_code		op;
}					t_move_plan;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
	t_move_plan		move_plan;
}					t_node;

typedef struct s_stack
{
	t_node			*sentinel;
	int				size;
	char			name;
}					t_stack;

// stack
t_node				*create_node(int value);
t_stack				*create_stack(char name);
void				free_stack(t_stack *s);
void				push(t_node *n, t_stack *s);
t_node				*pop(t_stack *s);
t_node				*get_max(t_stack *s);
t_node				*get_min(t_stack *s);

// stack cost calculations
void				assign_indices(t_stack *s);
t_node				*get_cheapest_node(t_stack *a, t_stack *b);
void				move_cheapest(t_stack *a, t_stack *b);
t_node				*get_cheapest_node(t_stack *a, t_stack *b);
void				set_node_move_plan(t_node *n, t_stack *a, t_stack *b);
void				set_target(t_node *n, t_stack *s);
void				reset_move_plan(t_node *n);

// stack sort
void				sort_stack(t_stack *s);
void				sort_stack_three(t_stack *s);
void				sort_stack_five(t_stack *a, t_stack *b);
void				sort_stack_larger_list(t_stack *a, t_stack *b);
bool				is_sorted_stack(t_stack *s);

// stack moves
void				p(t_stack *src, t_stack *dst);
void				s(t_stack *s);
void				ss(t_stack *s1, t_stack *s2);
void				r(t_stack *s);
void				rr(t_stack *s1, t_stack *s2);
void				rrx(t_stack *s);
void				rrr(t_stack *s1, t_stack *s2);

// array helpers:
int					*arr_sort(int *arr, int size);
int					arr_is_sorted(int *arr, int len);
int					*duplicate_arr(int *arr, int size);

// utils:
int					ft_atoi_arr_free(const char *nptr, int *arr);
void				put_str(char *s);
void				put_char(char c);
int					max(int n, int m);
int					min(int n, int m);
void				put_str(char *s);
void				put_char(char c);

// error handling
void				error_exit(void);
void				error_exit_free(int *a);

#endif
