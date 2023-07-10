/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:13:13 by besalort          #+#    #+#             */
/*   Updated: 2023/07/10 17:42:37 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_compare(t_lst *first, t_lst *second)
{
	if (first->value > second->value)
		return (1);
	return (2);
}

int	is_pile_sort(t_lst *pile)
{
	t_lst	*element;
	t_lst	*check;

	check = pile;
	while (check->next)
	{
		element = check->next;
		while (element)
		{
			if (check->value >= element->value)
			{
				return (0);
			}
			element = element->next;
		}
		check = check->next;
	}
	return (1);
}

int	is_highest(t_lst *pile)
{
	t_lst	*tmp;
	int		cmp;

	tmp = pile;
	cmp = tmp->value;
	while (tmp)
	{
		if (cmp < tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_lowest(t_lst *pile)
{
	t_lst	*tmp;
	int		cmp;

	tmp = pile;
	cmp = tmp->value;
	while (tmp)
	{
		if (cmp > tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_one_element(t_data *data, t_lst *pile, char c)
{
	t_lst	*tmp;
	int		cmp;

	tmp = pile->next;
	cmp = pile->value;
	if (is_pile_sort(pile) == 1 || is_lowest(pile) == 1)
		return ;
	if (is_highest(tmp) == 1)
	{
		rotate(data, c);
		return ;
	}
	if (cmp < tmp->value)
		return ;
	else
	{
		swap(data, c);
		if (is_pile_sort(pile) == 1)
			return ;
		rotate(data, c);
		sort_one_element(data, tmp, c);
	}
}
