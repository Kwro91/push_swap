/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:04:42 by besalort          #+#    #+#             */
/*   Updated: 2023/09/26 12:28:36 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	how_many_inf(t_lst *pile, int value)
{
	t_lst	*tmp;
	int		count;

	count = 0;
	tmp = pile;
	while (tmp)
	{
		if (tmp->value < value)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	how_many_supp(t_lst *pile, int value)
{
	t_lst	*tmp;
	int		count;

	count = 0;
	tmp = pile;
	while (tmp)
	{
		if (tmp->value > value)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
