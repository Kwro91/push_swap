/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:15:36 by besalort          #+#    #+#             */
/*   Updated: 2023/07/28 18:04:17 by besalort         ###   ########.fr       */
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

void	algo_test(t_data *data)
{
	push(data, 'b');
	push(data, 'b');
	sort_one_element(data, data->pile_b, 'b');
	while (ft_count_pile(data->pile_a) > 0)
	{
		push(data, 'b');
		sort_one_element(data, data->pile_b, 'b');
		// printpile(data);
		// while (is_pile_sort(data->pile_b) != 1)
		// {
		// 	// printf("Je me declenche\n");
		// 	// printpile(data);
		// 	put_right_order(data, data->pile_b, 'b');
		// }
	}
}

void	afficheall(t_data *data)
{
	int minimum;
	int	value;

	value = 100;
	minimum = 100;
	t_lst	*tmp;

	tmp = data->pile_b;
	while (tmp)
	{
		if (tmp->to_sort < minimum)
		{
			minimum = tmp->to_sort;
			value = tmp->value;	
		}
		tmp = tmp->next;
	}
	printf("la valeur la plus rapide a trier est %i avec %i coups necessaire\n", value, minimum);
}

void	algo_final(t_data *data, int elements)
{
	t_lst	*tmp;
	int		count;

	count = elements;
	tmp = data->pile_a;
	while (count > 3)
	{
		push(data, 'b');
		if (tmp->value >= data->mediane && count < elements)
			rotate(data, 'b');
		count--;
	}
	algo_3case(data);
	update_all_sort_indice(data);
	update_all_sort_time(data);
	afficheall(data);
	printpile(data);
}

void	algo(t_data *data)
{
	int	elements;

	elements = ft_count_pile(data->pile_a);
	printf("elements %i\n", elements);
	printpile(data);
	mediane(data, elements-1);
	// printf("Il y a %i elements dans la pile a\n", ft_count_pile(data->pile_a));
	if (elements == 2)
		swap(data, 'a');
	if (elements == 3)
		algo_3case(data);
	else if (elements > 3)
	{
		// algo_10case(data);
		// algo_test(data);
		algo_final(data, elements);
	}
}
