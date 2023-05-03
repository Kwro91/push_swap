/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:42:12 by besalort          #+#    #+#             */
/*   Updated: 2023/05/03 18:41:14 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*push(t_lst *element, t_lst *pile_to)
{
	t_lst	*last;
	t_lst	*pile_from;

	if (element->next)
		pile_from = element->next;
	else
		pile_from = NULL;
	if (pile_to)
	{
		last = pile_to;
		while (last->next)
			last = last->next;
		last->next = element;
		element->next = NULL;		
	}
	else
	{
		pile_to = element;
		pile_to->next = NULL;
	}
	return (pile_from);
}