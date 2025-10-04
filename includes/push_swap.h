/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:25:25 by MP9               #+#    #+#             */
/*   Updated: 2025/10/04 05:34:00 by MP9              ###   ########.fr       */
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
long	ft_atoli_support(char *str, long *number, long *prepoc);
char	*ft_inputjoin(char const *s1, char const *s2);
int		ft_stack_oldlen(char **numbers);
void	print_stack(t_stack *stack);
int		check_dup(t_stack *stack);
int		ft_numcmp(char **numbers);
void	free_stack(t_stack *stack);
void	free_all(t_stack *a, t_stack *b, char **nums, char **sorted_nums);
char	*ft_joinnfree(char *joinstr, const char *s2);

//stack creation
t_stack	*create_empty_stack(void);
void	add_node_into_stack(t_stack *stack, t_node *node);
void	build_stack(t_stack *a, t_stack *b, char **nums, char **s_nums);
t_node	*create_node(char *value, int index);

//parsing
char	**error_handle(char **argv, int argc);
void	error_handle2(char **bigstr);
char	*take_input(char **argv, int argc);
void	get_nums(char **bigstr);

//operations
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	swap(t_stack *stack);
void	push(t_stack *dest, t_stack *src);
//algorithm
void	radix_sort(t_stack *a, t_stack *b);
void	radix_support(t_stack *a, t_stack *b, int *i, int *size);
int		distance(t_stack *stack);
int		check_sort(t_stack *stack);
char	**sort_array(char **nums, int len);
void	sort_array_support(char **num, char **nxt_num, char *temp, int *swap);

#endif
