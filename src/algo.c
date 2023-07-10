/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:15:36 by besalort          #+#    #+#             */
/*   Updated: 2023/07/10 17:29:31 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_5case(t_data *data)
{
	push(data, 'b');
	push(data, 'b');
	//printpile(data); // CECI EST UNIQUEMENT POUR LES TESTS !!!
	algo_3case(data);
	//printpile(data); // CECI EST UNIQUEMENT POUR LES TESTS !!!
	push(data, 'a');
	//printpile(data); // CECI EST UNIQUEMENT POUR LES TESTS !!!
	sort_one_element(data, data->pile_a, 'a');
	push(data, 'a');
	//printpile(data); // CECI EST UNIQUEMENT POUR LES TESTS !!!
	sort_one_element(data, data->pile_a, 'a');
	put_right_order(data, data->pile_a, 'a');
}

void	algo_3case(t_data *data)
{
	t_lst	*tmp;

	tmp = data->pile_a;
	if (ft_compare(tmp, tmp->next) == 1)
	{
		swap(data, 'a');
	}
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
	else if (elements == 5)
		algo_5case(data);
	// reverse_rotate(data, 'a');
	// rotate(data, 'a');
	// push(data, 'b');
	// swap(data, 'a');
}
