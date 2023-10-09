/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:48:04 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 13:41:36 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_a(t_data *data)
{
	t_lst	*element;
	t_lst	*last;

	element = data->pile_a;
	last = data->pile_a;
	while (last->next)
		last = last->next;
	data->pile_a = data->pile_a->next;
	element->next = NULL;
	last->next = element;
	data->coups++;
}

void	rotate_b(t_data *data)
{
	t_lst	*element;
	t_lst	*last;

	element = data->pile_b;
	last = data->pile_b;
	while (last->next)
		last = last->next;
	data->pile_b = data->pile_b->next;
	element->next = NULL;
	last->next = element;
	data->coups++;
}

void	rotate(t_data *data, char p)
{
	if (p == 'a' && (ft_count_pile(data->pile_a) > 1))
		rotate_a(data);
	else if (p == 'b' && (ft_count_pile(data->pile_b) > 1))
		rotate_b(data);
	else if (p == 'r' && (ft_count_pile(data->pile_a)
			> 1 && ft_count_pile(data->pile_b) > 1))
	{
		rotate_a(data);
		rotate_b(data);
		data->coups--;
	}
}
