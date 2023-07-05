/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:42:15 by besalort          #+#    #+#             */
/*   Updated: 2023/07/05 16:31:37 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data)
{
	t_lst	*element;
	t_lst	*last;

	element = data->pile_a;
	last = data->pile_a;
	while(last->next)
		last = last->next;
	data->pile_a = data->pile_a->next;
	element->next = NULL;
	last->next = element;
}

void	rotate_b(t_data *data)
{
	t_lst	*element;
	t_lst	*last;

	element = data->pile_b;
	last = data->pile_b;
	while(last->next)
		last = last->next;
	data->pile_b = data->pile_b->next;
	element->next = NULL;
	last->next = element;
}

void	rotate(t_data *data, char p)
{
	//Ajouter des verifs
	if (p == 'a')
		rotate_a(data);
	else if (p == 'b')
		rotate_b(data);
}