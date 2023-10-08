/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:18:19 by besalort          #+#    #+#             */
/*   Updated: 2023/10/08 18:13:32 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void    free_cmds(t_data *data)
{
    int i;

    i = 0;
    if (!data->cmds)
        return ;
    while (data->cmds[i])
    {
        free(data->cmds[i]);
        i++;
    }
    free(data->cmds);
}

void    cmd_stack(t_data *data, char *line)
{
    char    **tmp;
    int     i;
    int     count;

    i = 0;
    count = 0;
    while(data->cmds && data->cmds[count])
        count++;
    tmp = malloc(sizeof(char *) * (count + 2));
    while (i < count)
    {
        if (data->cmds[i])
            tmp[i] = ft_strdup(data->cmds[i]);
        i++;
    }
    tmp[i] = ft_strdup(line);
    tmp[i+1] = NULL;
    free_cmds(data);
    data->cmds = tmp;
}

void    read_all(t_data *data)
{
    char    *line;

    while (1)
    {
        line = get_next_line(0);
        if (line == NULL)
            break;
        cmd_stack(data, line);
    }
}