/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:22:52 by besalort          #+#    #+#             */
/*   Updated: 2023/07/05 16:31:19 by besalort         ###   ########.fr       */
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
	while(last->next != element)
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
	while(last->next != element)
		last = last->next;
    last->next = NULL;
	data->pile_b = element;
}

void    reverse_rotate(t_data *data, char p)
{
    //Ajouter des verifs
    if (p == 'a')
		reverse_rotate_a(data);
	else if (p == 'b')
		reverse_rotate_b(data);
}