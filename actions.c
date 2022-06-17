/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:11:16 by rarthric          #+#    #+#             */
/*   Updated: 2022/03/11 16:11:22 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	ra
void	ft_ra(t_stack **a, int i)
{
	t_stack	*first_list;
	t_stack	*rotate_list;
	t_stack	*last_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	rotate_list = *a;
	first_list = (*a)->next;
	last_list = *a;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*a = first_list;
	if (i == 1)
		write(1, "ra\n", 3);
}

//	rb
void	ft_rb(t_stack **b, int i)
{
	t_stack	*first_list;
	t_stack	*rotate_list;
	t_stack	*last_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	rotate_list = *b;
	first_list = (*b)->next;
	last_list = *b;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*b = first_list;
	if (i == 1)
		write(1, "rb\n", 3);
}

//	rr
void	ft_rr(t_stacks *s, int i)
{
	if (i == 1)
		write(1, "rr\n", 3);
	ft_ra(&s->a, 0);
	ft_rb(&s->b, 0);
}

//	rra
void	ft_rra(t_stack **a, int i)
{
	t_stack		*first_list;
	t_stack		*rotate_list;
	t_stack		*penultimate_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	first_list = *a;
	penultimate_list = *a;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	*a = rotate_list;
	if (i == 1)
		write(1, "rra\n", 4);
}

//	rrb
void	ft_rrb(t_stack **b, int i)
{
	t_stack		*first_list;
	t_stack		*rotate_list;
	t_stack		*penultimate_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	first_list = *b;
	penultimate_list = *b;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	*b = rotate_list;
	if (i == 1)
		write(1, "rrb\n", 4);
}
