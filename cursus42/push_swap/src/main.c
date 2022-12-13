/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:59:01 by afavre            #+#    #+#             */
/*   Updated: 2022/12/07 13:28:59 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	set_data(char **av, char **data)
{
	int	i;

	i = 0;
	while (data[i] != NULL)
	{
		av[i + 1] = data[i];
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**data;
	int		size;

	size = ac - 1;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		data = ft_split(av[1], ' ');
		size = set_data(av, data);
	}
	if (!is_correct_input(size, av))
		exit_error(NULL, NULL, "Invalid input");
	stack_a = fill_stack_values(size, av);
	stack_b = NULL;
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
