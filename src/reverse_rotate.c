/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:22:52 by besalort          #+#    #+#             */
/*   Updated: 2023/07/11 15:56:25 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

void	reverse_rotate(t_data *data, char p)
{
	ft_printf("rr%c\n", p);
	if (p == 'a' && (ft_count_pile(data->pile_a) > 1))
	{
		reverse_rotate_a(data);
		data->coups++;
	}
	else if (p == 'b' && (ft_count_pile(data->pile_b) > 1))
	{
		reverse_rotate_b(data);
		data->coups++;
	}
	else
		ft_printf("Impossible de reverse_rotate\n");
}
