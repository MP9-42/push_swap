/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:25 by MP9               #+#    #+#             */
/*   Updated: 2025/09/11 00:11:10 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef ERROR_MSG
#  define ERROR_MSG "Error\n"
# endif

typedef struct s_stack_old
{
	int					value;
	struct s_stack_old		*next;
}				t_stack_old;

typedef struct s_sort
{
	t_stack_old			*stack_a;
	t_stack_old			*stack_b;
}					t_sort;

typedef struct s_node
{
    int                 value;
    struct s_node       *next;
    struct s_node       *prev;
    int                 index;
}               t_node;

typedef struct s_stack
{
    t_node          *head;
    t_node          *tail;
    int             size;
}                   t_stack;



//utils
void		free_matrix(char **matrix);
void		*ft_memmove(void *dst, const void *src, size_t len);
long		ft_atoli(char *str);
char		*ft_inputjoin(char const *s1, char const *s2);
int			ft_stack_oldlen(int *stack);
char		**check_dup(char **matrix);

//stack creation
t_sort		*create_stacks(int *numbers);
t_stack_old		*stack_allocate(int *numbers);
t_stack_old		*assign_values(t_stack_old *stack, int *numbers);

//parsing
int			*error_handle(char **argv, int argc);
char		**error_handle2(char **bigstr);
char		*take_input(char **argv, int argc);
int			*get_nums(char **bigstr);
int			*stackerror(char **matrix, int *stack_a);

//algorithm
t_stack_old		*rrotate(t_stack_old *stack);
int			*asort(int *stack_a, int len);
int			*bsort(int *stack_a, int *stack_b, int len);
int			*pushnrotate(int *stack_a, int *stack_b, int len);
int			*rotate(int *stack, int len);

//print array int
void print_array(int *array_num, char *name_array);

#endif
