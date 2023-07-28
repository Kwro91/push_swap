/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_indice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:05:49 by besalort          #+#    #+#             */
/*   Updated: 2023/07/28 18:24:57 by besalort         ###   ########.fr       */
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
		printf("%i est mon sort indice et on compte %i movement pour pouvoir etre push\n", tmp->sort_indice, move_in_pile_b);
		if (tmp->sort_indice == 0)//au debut
		{
			printf("au debut\n");
			tmp->to_sort = 1 + move_in_pile_b;
		} 
		else if (tmp->sort_indice <= ft_count_pile(data->pile_a)/2) //le ranger dans la premiere moitiee d'indice
		{
			printf("le ranger dans la premiere moitiee d'indice\n");
			tmp->to_sort = 1 + tmp->sort_indice * 2 - 1 + move_in_pile_b;
		}
		else if (tmp->sort_indice == ft_count_pile(data->pile_a)) //a la fin
		{
			printf("a la fin\n");
			tmp->to_sort = 2 + move_in_pile_b;
		}
		else //le ranger dans la deuxieme moitiee d'indice
		{
			printf("le ranger dans la deuxieme moitiee d'indice\n");
			tmp->to_sort = 1 + (ft_count_pile(data->pile_a) - tmp->sort_indice) * 2 + move_in_pile_b;
		}
		printf("la valeur %i est triee en %icoups\n\n", tmp->value, tmp->to_sort);
		tmp = tmp->next;
	}
}

