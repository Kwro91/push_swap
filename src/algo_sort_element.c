/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:20:06 by besalort          #+#    #+#             */
/*   Updated: 2023/07/20 17:36:07 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_by_rotate(t_data *data, t_lst *pile, char c, int count)
{
	printf("sort by rotate et il reste %i fois\n", count);
	if (count == 0)
		return ;
	swap(data, c);
	rotate(data, c);
	sort_by_rotate(data, pile, c, count-1);
	reverse_rotate(data, c);
}

void	sort_by_reverse_rotate(t_data *data, t_lst *pile, char c, int count)
{
	if (count == 0)
		return ;
	reverse_rotate(data, c);
	swap(data, c);
	sort_by_reverse_rotate(data, pile, c, count-1);
	rotate(data, c);
	if (count <= 1)
		rotate(data, c);
}

void	rotate_or_reverse_rotate(t_data *data, t_lst *pile, char c)
{
	int rotate;
	int	reverse_rotate;

	rotate = 0;
	reverse_rotate = 0;
	rotate = how_many_inf(pile, pile->value);
	reverse_rotate = how_many_supp(pile, pile->value);
	if (rotate <= reverse_rotate)
		sort_by_rotate(data, pile, c, rotate);
	else
		sort_by_reverse_rotate(data, pile, c, reverse_rotate);
}

void	sort_one_element(t_data *data, t_lst *pile, char c)
{
	t_lst	*tmp;
	int		cmp;

	tmp = pile->next;
	cmp = pile->value;
	if (is_pile_sort(pile) == 1 || is_lowest(pile) == 1)
		return ;
	if (is_highest(pile) == 1)
	{
		rotate(data, c);
		return ;
	}
	if (cmp < tmp->value)
		return ;
	else
		rotate_or_reverse_rotate(data, pile, c);
}
