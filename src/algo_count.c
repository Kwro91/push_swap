/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:04:42 by besalort          #+#    #+#             */
/*   Updated: 2023/07/17 17:01:42 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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