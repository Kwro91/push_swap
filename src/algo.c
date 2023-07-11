/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:15:36 by besalort          #+#    #+#             */
/*   Updated: 2023/07/11 18:25:38 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_10case(t_data *data)
{
	while (ft_count_pile(data->pile_a) != 3)
		push(data, 'b');
	//printpile(data); // CECI EST UNIQUEMENT POUR LES TESTS !!!
	algo_3case(data);
	sort_one_element(data, data->pile_b, 'b');
	while (ft_count_pile(data->pile_b) != 0)
	{
		push(data, 'a');
		sort_one_element(data, data->pile_a, 'a');
	}
	while (is_pile_sort(data->pile_a) != 1)
	{
		// printpile(data); // CECI EST UNIQUEMENT POUR LES TESTS !!!
		put_right_order(data, data->pile_a, 'a');
	}
}

void	algo_3case(t_data *data)
{
	t_lst	*tmp;

	tmp = data->pile_a;
	if (is_highest(tmp) == 1)
		rotate(data, 'a');
	else if (ft_compare(tmp, tmp->next) == 1)
		swap(data, 'a');
	else
		reverse_rotate(data, 'a');
	if (is_pile_sort(data->pile_a) == 0)
		algo_3case(data);
}

void	algo(t_data *data)
{
	int	elements;

	elements = ft_count_pile(data->pile_a);
	printf("Il y a %i elements dans la pile a\n", ft_count_pile(data->pile_a));
	// printf("Il y a %i elements dans la pile b\n", ft_count_pile(data->pile_b));
	if (elements == 3)
		algo_3case(data);
	else if (elements <= 10)
		algo_10case(data);
	// reverse_rotate(data, 'a');
	// rotate(data, 'a');
	// push(data, 'b');
	// swap(data, 'a');
}
