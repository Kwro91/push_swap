/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmds_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:00:28 by besalort          #+#    #+#             */
/*   Updated: 2023/10/13 19:22:20 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_push(t_data *data, char *cmd)
{
	if (ft_strncmp("pa\n", cmd, 3) == 0)
	{
		push(data, 'a');
		return (1);
	}
	else if (ft_strncmp("pb\n", cmd, 3) == 0)
	{
		push(data, 'b');
		return (1);
	}
	return (0);
}

int	is_swap(t_data *data, char *cmd)
{
	if (ft_strncmp("sa\n", cmd, 3) == 0)
	{
		swap(data, 'a');
		return (1);
	}
	else if (ft_strncmp("sb\n", cmd, 3) == 0)
	{
		swap(data, 'b');
		return (1);
	}
	return (0);
}

int	is_rotate(t_data *data, char *cmd)
{
	if (ft_strncmp("ra\n", cmd, 3) == 0)
	{
		rotate(data, 'a');
		return (1);
	}
	else if (ft_strncmp("rb\n", cmd, 3) == 0)
	{
		rotate(data, 'b');
		return (1);
	}
	else if (ft_strncmp("rr\n", cmd, 3) == 0)
	{
		rotate(data, 'r');
		return (1);
	}
	return (0);
}

int	is_reverse_rotate(t_data *data, char *cmd)
{
	if (ft_strncmp("rra\n", cmd, 4) == 0)
	{
		reverse_rotate(data, 'a');
		return (1);
	}
	else if (ft_strncmp("rrb\n", cmd, 4) == 0)
	{
		reverse_rotate(data, 'b');
		return (1);
	}
	else if (ft_strncmp("rrr\n", cmd, 4) == 0)
	{
		reverse_rotate(data, 'r');
		return (1);
	}
	return (0);
}

int	do_cmds(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmds && data->cmds[i])
	{
		if (is_push(data, data->cmds[i]) == 0
			&& is_rotate(data, data->cmds[i]) == 0
			&& is_reverse_rotate(data, data->cmds[i]) == 0
			&& is_swap(data, data->cmds[i]) == 0)
			return (-1);
		if (ft_strncmp("Error\n", data->cmds[i], 6) == 0)
			return (-1);
		i++;
	}
	if (is_pile_sort(data->pile_a) == 1 && data->pile_b == NULL)
		return (1);
	else if (is_pile_sort(data->pile_b) == 1 && data->pile_a == NULL)
		return (1);
	return (0);
}
