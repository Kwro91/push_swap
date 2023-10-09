/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmds_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:00:28 by besalort          #+#    #+#             */
/*   Updated: 2023/10/09 16:34:29 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	is_push(t_data *data, char *cmd)
{
	if (ft_strncmp("pa\n", cmd, 3) == 0)
		push(data, 'a');
	else if (ft_strncmp("pb\n", cmd, 3) == 0)
		push(data, 'b');
}

void	is_swap(t_data *data, char *cmd)
{
	if (ft_strncmp("sa\n", cmd, 3) == 0)
		swap(data, 'a');
	else if (ft_strncmp("sb\n", cmd, 3) == 0)
		swap(data, 'b');
}

void	is_rotate(t_data *data, char *cmd)
{
	if (ft_strncmp("ra\n", cmd, 3) == 0)
		rotate(data, 'a');
	else if (ft_strncmp("rb\n", cmd, 3) == 0)
		rotate(data, 'b');
	else if (ft_strncmp("rr\n", cmd, 3) == 0)
		rotate(data, 'r');
}

void	is_reverse_rotate(t_data *data, char *cmd)
{
	if (ft_strncmp("rra\n", cmd, 4) == 0)
		reverse_rotate(data, 'a');
	else if (ft_strncmp("rrb\n", cmd, 4) == 0)
		reverse_rotate(data, 'b');
	else if (ft_strncmp("rrr\n", cmd, 4) == 0)
		reverse_rotate(data, 'r');
}

int	do_cmds(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmds && data->cmds[i])
	{
		is_push(data, data->cmds[i]);
		is_rotate(data, data->cmds[i]);
		is_reverse_rotate(data, data->cmds[i]);
		is_swap(data, data->cmds[i]);
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
