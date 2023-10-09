/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_indice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:05:49 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 13:18:04 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	value_of_last(t_lst *pile)
{
	t_lst	*tmp;

	tmp = pile;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

int	which_highest(t_lst *pile)
{
	t_lst	*tmp;

	tmp = pile;
	while (tmp)
	{
		if (is_highest(tmp) == 1)
			return (tmp->indice);
		tmp = tmp->next;
	}
	return (0);
}

int	which_lowest(t_lst *pile)
{
	t_lst	*tmp;

	tmp = pile;
	while (tmp)
	{
		if (is_lowest(tmp) == 1)
			return (tmp->indice);
		tmp = tmp->next;
	}
	return (0);
}

int	indice_sort(t_data *data, int value)
{
	t_lst	*before;
	t_lst	*after;
	int		is_lowest;

	is_lowest = 1;
	before = data->pile_a;
	after = before->next;
	if (before->value > value && (value_of_last(data->pile_a) < value))
		return (0);
	while (after)
	{
		if (is_lowest == 1 && before->value < value)
			is_lowest = 0;
		if (before->value < value && after->value > value)
			return (after->indice);
		before = before->next;
		after = after->next;
	}
	if (is_lowest == 1)
		return (which_lowest(data->pile_a));
	if (which_highest(data->pile_a) == ft_count_pile(data->pile_a) - 1)
		return (0);
	return (which_highest(data->pile_a) + 1);
}
