/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_re-order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:45:22 by besalort          #+#    #+#             */
/*   Updated: 2023/07/17 15:05:43 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_for_reverse(t_lst *pile, int save)
{
	t_lst	*tmp;
	int 	count_start;
	
	
	count_start = 0;
	tmp = pile;
	while (tmp && tmp->value < save)
		tmp = tmp->next;
	while (tmp)
	{
		count_start++;
		tmp = tmp->next;
	}
	return count_start;
}

int	ft_count_for_rotate(t_lst *pile, int save)
{
	int		count_end;
	t_lst	*tmp;

	tmp = pile;
	count_end = 0;
	while (tmp && tmp->value < save)
	{
		save = tmp->value;
		tmp = tmp->next;
		count_end++;
	}
	return count_end;
}

void	put_at_the_end(t_data *data, t_lst *pile, char c, int count)
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
	if (is_pile_sort(tmp) == 0 && count > 0)
		put_at_the_end(data, tmp, c, count-1);
}

void	put_at_the_start(t_data *data, t_lst *pile, char c, int count)
{
	t_lst	*tmp;

	tmp = pile;
	while (tmp->next)
		tmp = tmp->next;
	reverse_rotate(data, c);
	if (is_pile_sort(tmp) == 0 && count > 0)
		put_at_the_start(data, tmp, c, count-1);
}

void	put_right_order(t_data *data, t_lst *pile, char c)
{
	int save;
	int rotate;
	int reverse;

	rotate = 0;
	reverse = 0;
	save = pile->value;
	rotate = ft_count_for_rotate(pile, save);
	reverse = ft_count_for_reverse(pile, save);
	if (rotate < reverse)
		put_at_the_end(data, pile, c, rotate);
	else
		put_at_the_start(data, pile, c, reverse);
}
