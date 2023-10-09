/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:47:54 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 13:43:13 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate_a(t_data *data)
{
	t_lst	*element;
	t_lst	*last;

	element = data->pile_a;
	while (element->next)
		element = element->next;
	element->next = data->pile_a;
	last = data->pile_a;
	while (last->next != element)
		last = last->next;
	last->next = NULL;
	data->pile_a = element;
	data->coups++;
}

void	reverse_rotate_b(t_data *data)
{
	t_lst	*element;
	t_lst	*last;

	element = data->pile_b;
	while (element->next)
		element = element->next;
	element->next = data->pile_b;
	last = data->pile_b;
	while (last->next != element)
		last = last->next;
	last->next = NULL;
	data->pile_b = element;
	data->coups++;
}

void	reverse_rotate(t_data *data, char p)
{
	if (p == 'a' && (ft_count_pile(data->pile_a) > 1))
		reverse_rotate_a(data);
	else if (p == 'b' && (ft_count_pile(data->pile_b) > 1))
		reverse_rotate_b(data);
	else if (p == 'r' && (ft_count_pile(data->pile_a)
			> 1 && (ft_count_pile(data->pile_b) > 1)))
	{
		reverse_rotate_a(data);
		reverse_rotate_b(data);
		data->coups--;
	}
}
