/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_re-order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:45:22 by besalort          #+#    #+#             */
/*   Updated: 2023/07/10 17:41:22 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_for_rotate_case(t_lst *pile)
{
	int		save;
	int		count_start;
	int		count_end;
	t_lst	*tmp;

	tmp = pile;
	save = tmp->value;
	count_start = 0;
	count_end = 0;
	while (tmp)
	{
		save = tmp->value;
		tmp = tmp->next;
		count_end++;
		if (tmp->value < save)
			break ;
	}
	while (tmp)
	{
		count_start++;
		tmp = tmp->next;
	}
	if (count_start >= count_end)
		return (1);
	return (2);
}

void	put_at_the_end(t_data *data, t_lst *pile, char c)
{
	t_lst	*tmp;
	t_lst	*last;

	tmp = pile;
	last = pile;
	while (last->next)
		last = last->next;
	if (tmp->value > last->value)
	{
		tmp = tmp->next;
		rotate(data, c);
	}
	if (is_pile_sort(tmp) == 0)
		put_at_the_end(data, tmp, c);
}

void	put_at_the_start(t_data *data, t_lst *pile, char c)
{
	t_lst	*tmp;

	tmp = pile;
	while (tmp->next)
		tmp = tmp->next;
	reverse_rotate(data, c);
	if (is_pile_sort(tmp) == 0)
		put_at_the_start(data, tmp, c);
}

void	put_right_order(t_data *data, t_lst *pile, char c)
{
	int	value;

	value = 0;
	value = ft_count_for_rotate_case(pile);
	if (value == 1)
		put_at_the_end(data, pile, c);
	else if (value == 2)
		put_at_the_start(data, pile, c);
}
