/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:05:46 by besalort          #+#    #+#             */
/*   Updated: 2023/10/08 17:32:08 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
