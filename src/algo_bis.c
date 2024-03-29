/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:13:13 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 13:12:51 by besalort         ###   ########.fr       */
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
	if (check == NULL)
	{
		return (1);
	}
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

int	ft_count_pile(t_lst *pile)
{
	int		count;
	t_lst	*tmp;

	count = 0;
	tmp = pile;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
