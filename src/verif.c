/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:21:25 by besalort          #+#    #+#             */
/*   Updated: 2023/05/03 18:44:26 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_double_in_lst(t_data *data)
{
	t_lst 	*element;
	t_lst	*check;
	
	check = data->pile_a;
	while (check->next)
	{
		element = check->next;
		while (element)
		{
			if (check->value == element->value)
			{
				return (1);
			}
			element = element->next;
		}
		check = check->next;
	}
	return (0);
}

int	is_sort(t_data *data)
{
	t_lst 	*element;
	t_lst	*check;
	
	check = data->pile_a;
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

int	verif(t_data *data)
{
	if (is_sort(data) == 1)
		return (-1);
	if (is_double_in_lst(data) == 1)
		return (-1);
	return (0);
}