/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:13:32 by rarthric          #+#    #+#             */
/*   Updated: 2022/03/11 16:13:34 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	ft_action_processing -  Запуск нужной функции.
void	ft_action_processing(char *line, t_stacks *s)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(s->a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(s->b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(s, 0);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(s, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(s, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(&s->a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(&s->b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(s, 0);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(&s->a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(&s->b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(s, 0);
	else
		ft_error();
}

//	ft_read_action - ввод команды из консоли в функцию обработки.
void	ft_read_action(t_stacks *s)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		ft_action_processing(line, s);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

//		ft_stack_sorted -  проверка стека на отсортированность.
int	ft_stack_sorted(t_stacks *s)
{
	int		i;
	int		buff;
	t_stack	*save;

	i = 0;
	save = s->a;
	while (i < (s->count_a - 1))
	{
		buff = s->a->data;
		s->a = s->a->next;
		if (buff > s->a->data)
		{
			s->a = save;
			return (0);
		}
		i++;
	}
	s->a = save;
	return (1);
}

static void	ft_squeeze(int argc, char **argv, t_data *new, t_stacks *stacks)
{
	ft_array_separation(argc, argv, new);
	ft_duplicate_check(new, stacks);
	ft_init_stack(new, stacks);
	ft_read_action(stacks);
	if ((ft_stack_sorted(stacks)) && stacks->count_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		exit(1);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		exit(1);
	ft_null(stacks, new);
	if (ft_validation(argc, argv))
		ft_squeeze(argc, argv, new, stacks);
	ft_free_stack(stacks);
	free(new);
	free(stacks);
	return (0);
}
