/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_indice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:05:49 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 12:08:58 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	value_of_last(t_lst *pile)
{
	t_lst	*tmp;

	tmp = pile;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

int	which_highest(t_lst *pile)
{
	t_lst	*tmp;

	tmp = pile;
	while (tmp)
	{
		if (is_highest(tmp) == 1)
			return (tmp->indice);
		tmp = tmp->next;
	}
	return (0);
}

int	which_lowest(t_lst *pile)
{
	t_lst	*tmp;

	tmp = pile;
	while (tmp)
	{
		if (is_lowest(tmp) == 1)
			return (tmp->indice);
		tmp = tmp->next;
	}
	return (0);
}

int	indice_sort(t_data *data, int value)
{
	t_lst	*before;
	t_lst	*after;
	int		is_lowest;

	is_lowest = 1;
	before = data->pile_a;
	after = before->next;
	if (before->value > value && (value_of_last(data->pile_a) < value))
		return (0);
	while (after)
	{
		if (is_lowest == 1 && before->value < value)
			is_lowest = 0;
		if (before->value < value && after->value > value)
			return (after->indice);
		before = before->next;
		after = after->next;
	}
	if (is_lowest == 1)
		return (which_lowest(data->pile_a));
	if (which_highest(data->pile_a) == ft_count_pile(data->pile_a) - 1)
		return (0);
	return (which_highest(data->pile_a) + 1);
}

void	update_all_sort_indice(t_data *data)
{
	t_lst	*tmp;

	tmp = data->pile_b;
	while (tmp)
	{
		tmp->sort_indice = indice_sort(data, tmp->value);
		tmp = tmp->next;
	}
}

void	update_all_sort_time(t_data *data)
{
	t_lst	*tmp;
	int		move_in_pile_b;

	tmp = data->pile_b;
	while (tmp)
	{
		move_in_pile_b = tmp->indice;
		if (tmp->indice > ft_count_pile(data->pile_b)/2)
			move_in_pile_b = (ft_count_pile(data->pile_b) - tmp->indice);
		if (tmp->sort_indice == 0)
		{
			tmp->to_sort = 1 + move_in_pile_b;
		} 
		else if (tmp->sort_indice <= ft_count_pile(data->pile_a)/2)
		{
			tmp->to_sort = 1 + tmp->sort_indice - 1 + move_in_pile_b;
		}
		else if (tmp->sort_indice == ft_count_pile(data->pile_a))
		{
			tmp->to_sort = 1 + move_in_pile_b;
		}
		else
		{
			tmp->to_sort = 1 + (ft_count_pile(data->pile_a) - tmp->sort_indice) + move_in_pile_b;
		}
		tmp = tmp->next;
	}
}

int	chose_fastest(t_data *data)
{
	int		indice;
	int		fastest;
	t_lst	*tmp;

    indice = 0;
	fastest = 1000;
	tmp = data->pile_b;
	while (tmp)
	{
		if (tmp->to_sort < fastest)
		{
			fastest = tmp->to_sort;
			indice = tmp->indice;
		}
		tmp = tmp->next;
	}
	return (indice);
}

void	prepare_to_sort(t_data *data, int indice, int r_done)
{
	t_lst	*tmp;

	indice = indice - r_done;
	tmp = data->pile_b;
	while(tmp && tmp->indice != indice)
		tmp = tmp->next;
    if (tmp)
	    tmp->sort_indice = tmp->sort_indice - r_done;
	if (indice > ft_count_pile(data->pile_b)/2)
	{
		while (tmp && tmp->indice != 0)
			reverse_rotate(data, 'b');
	}
	else
		while (tmp && tmp->indice != 0)
			rotate(data, 'b');
}

void	sort_rotate(t_data *data, int indice)
{
	int	count;

	count = 0;
	if (indice == 0 && is_highest(data->pile_a) == 1)
		return ;
	while (count < indice)
	{
		rotate(data, 'a');
		count++;
	}
}

void	sort_reverse(t_data *data, int indice)
{
	int	count;

	count = 0;
	while (count < indice)
	{
		reverse_rotate(data, 'a');
		count++;
	}
}

void	sort_all(t_data *data)
{
	int	count;
	t_lst	*tmp;

    update_all_sort_indice(data);
	tmp = data->pile_b;
	count = tmp->sort_indice;
	if (count != 0 && tmp->sort_indice >= (ft_count_pile(data->pile_a)/2 - 1))
	{
		count = ft_count_pile(data->pile_a) - tmp->sort_indice;
		sort_reverse(data, count);
	}
	else if (count != 0)
		sort_rotate(data, count);
	push(data, 'a');
}

void	reorder_pile(t_data *data)
{
	int	chose;

	chose = which_lowest(data->pile_a);
	if (ft_count_pile(data->pile_a)/2 > chose)
	{
		while(which_lowest(data->pile_a) != 0)
			reverse_rotate(data, 'a');
	}
	else
	{
		while (which_lowest(data->pile_a) != 0)
			rotate(data, 'a');
	}
}


int	using_r(t_data* data, int indice)
{
	t_lst	*tmp;
	int		count;

	count = 0;
	tmp = data->pile_b;
	while (tmp && tmp->indice != indice)
		tmp = tmp->next;
	if (tmp->to_sort == 0 || indice == 0)
		return (count);
	if (indice < ft_count_pile(data->pile_b)/2)
	{
		if (tmp->sort_indice < ft_count_pile(data->pile_a)/2)
		{
			while (count < indice && count < tmp->sort_indice)
			{
				rotate(data, 'r');
				count++;
			}
		}
	}
	else
	{
		if (tmp->sort_indice >= ft_count_pile(data->pile_a)/2)
		{
			// while (count < (ft_count_pile(data->pile_a) - tmp->sort_indice) && count < (ft_count_pile(data->pile_b) - indice))
			while(count < (ft_count_pile(data->pile_a) - tmp->sort_indice) && tmp->indice > 0)
            {
				reverse_rotate(data, 'r');
				count++;
			}
            count = -count;
		}
	}
	return (count);
}