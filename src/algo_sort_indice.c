/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_indice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:05:49 by besalort          #+#    #+#             */
/*   Updated: 2023/07/31 18:03:11 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int which_highest(t_lst *pile)
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

int which_lowest(t_lst *pile)
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
	t_lst 	*before;
	t_lst	*after;
	int		is_lowest;

	is_lowest = 1;
	before = data->pile_a;
	after = before->next;
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
	return (which_highest(data->pile_a)+1);
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
		// printf("%i est mon sort indice et on compte %i movement pour pouvoir etre push\n", tmp->sort_indice, move_in_pile_b);
		if (tmp->sort_indice == 0)//au debut
		{
			// printf("au debut\n");
			tmp->to_sort = 1 + move_in_pile_b;
		} 
		else if (tmp->sort_indice <= ft_count_pile(data->pile_a)/2) //le ranger dans la premiere moitiee d'indice
		{
			// printf("le ranger dans la premiere moitiee d'indice\n");
			tmp->to_sort = 1 + tmp->sort_indice * 2 - 1 + move_in_pile_b;
		}
		else if (tmp->sort_indice == ft_count_pile(data->pile_a)) //a la fin
		{
			// printf("a la fin\n");
			tmp->to_sort = 2 + move_in_pile_b;
		}
		else //le ranger dans la deuxieme moitiee d'indice
		{
			// printf("le ranger dans la deuxieme moitiee d'indice\n");
			tmp->to_sort = 1 + (ft_count_pile(data->pile_a) - tmp->sort_indice) * 2 + move_in_pile_b;
		}
		// printf("la valeur %i est triee en %icoups\n\n", tmp->value, tmp->to_sort);
		tmp = tmp->next;
	}
}

int	chose_fastest(t_data *data)
{
	int		indice;
	int		fastest;
	t_lst	*tmp;

	fastest = 100;
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

void	prepare_to_sort(t_data *data, int indice)
{
	t_lst	*tmp;

	while(tmp && tmp->indice != indice)
		tmp = tmp->next;
	if (indice > ft_count_pile(data->pile_b)/2)
	{
		while (tmp && tmp->indice != 0)
			reverse_rotate(data, 'b');
	}
	else
		while (tmp && tmp->indice != 0)
			rotate(data, 'b');
	push(data, 'a');
}

int	value_of_last(t_lst *pile)
{
	t_lst *tmp;
	tmp = pile;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

void	sort_fastest(t_data *data)
{
	t_lst	*tmp;
	t_lst	*after;

	tmp = data->pile_a;
	printf("tmp sort indice est de %i\n", tmp->sort_indice);
	after = tmp->next;
	if (tmp->sort_indice == 0)
		return ;
	if (tmp->sort_indice > ft_count_pile(data->pile_a)/2)
	{
		printf("test1 tmp value :%i et after value %i\n", tmp->value, after->value);
		while(after && ((after->value < tmp->value) || (value_of_last(data->pile_a) > tmp->value)))
		{
			reverse_rotate(data, 'a');
			swap(data, 'a');
			after = tmp->next;
		}
	}
	else if (tmp->sort_indice <= ft_count_pile(data->pile_a)/2)
	{
		printf("test2\n");
		while(after && after->value < tmp->value)
		{
			swap(data, 'a');
			rotate(data, 'a');
			tmp = data->pile_a;
			after = tmp->next;
		}
	}
}