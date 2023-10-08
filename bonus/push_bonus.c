/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:48:22 by besalort          #+#    #+#             */
/*   Updated: 2023/10/08 18:20:42 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_to_a(t_data *data)
{
	t_lst	*element;

	element = data->pile_b;
	if (!element->next)
		data->pile_b = NULL;
	else
		data->pile_b = data->pile_b->next;
	if (data->pile_a)
		element->next = data->pile_a;
	else
		element->next = NULL;
	data->pile_a = element;
	data->coups++;
}

void	push_to_b(t_data *data)
{
	t_lst	*element;

	element = data->pile_a;
	if (!element->next)
		data->pile_a = NULL;
	else
		data->pile_a = data->pile_a->next;
	if (data->pile_b)
		element->next = data->pile_b;
	else
		element->next = NULL;
	data->pile_b = element;
	data->coups++;
}

void	push(t_data *data, char p)
{
	if (p == 'a' && data->pile_b)
		push_to_a(data);
	else if (p == 'b' && data->pile_a)
		push_to_b(data);
}
