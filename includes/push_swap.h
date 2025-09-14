/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:25 by MP9               #+#    #+#             */
/*   Updated: 2025/09/14 18:10:59 by MP9              ###   ########.fr       */
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

typedef struct s_node
{
	int					value;
	struct s_node		*next;
	struct s_node		*prev;
	int					index;
}				t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
}				t_stack;

//utils
void	free_matrix(char **matrix);
void	*ft_memmove(void *dst, const void *src, size_t len);
long	ft_atoli(char *str);
char	*ft_inputjoin(char const *s1, char const *s2);
int		ft_stack_oldlen(int *stack);
void	print_stack(t_stack *stack);
char	**check_dup(char **matrix);
void	free_node(t_node *node);
void	free_all(t_stack *a, t_stack *b, int *nums, int *sorted_nums);

//stack creation
t_stack	*create_empty_stack(void);
void	add_node_into_stack(t_stack *stack, t_node *node);
void	build_stack(t_stack *stack_a, int *numbers, int *sorted_nums);
t_node	*create_node(int value, int index);

//parsing
int		*error_handle(char **argv, int argc);
char	**error_handle2(char **bigstr);
char	*take_input(char **argv, int argc);
int		*get_nums(char **bigstr);
int		*stackerror(char **matrix, int *stack_a);

//operations
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	swap(t_stack *stack);
void	push(t_stack *dest, t_stack *src);
//algorithm
void	k_sort(t_stack *a, t_stack *b);
int		find_max_bits(t_stack *a);

//print array int
void	print_array(int *array_num, char *name_array);

#endif
