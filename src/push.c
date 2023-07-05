/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:42:12 by besalort          #+#    #+#             */
/*   Updated: 2023/07/05 16:43:41 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_data *data)
{
	t_lst *element;

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
}

void	push_to_b(t_data *data)
{
	t_lst *element;

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
}

void	push(t_data *data, char p)
{
	//Ajouter des verifs
	if (p == 'a')
		push_to_a(data);
	else if (p == 'b')
		push_to_b(data);
}
