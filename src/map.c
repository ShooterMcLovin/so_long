/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:27:23 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/04 09:59:32 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_map(t_data *data, char *av)
{
	int	fd;
	int	s;

	data->map_height = 0;
	s = 1;
	fd = open(av, 0);
	if (fd < 0)
		ft_error_close();
	while (s)
	{
		data->map[data->map_height] = get_next_line(fd);
		if (data->map[data->map_height] == NULL)
			s = 0;
		if (data->map[data->map_height] == NULL && data->map_height == 0)
			ft_error_close();
		data->map_height++;
	}
	data->map_height -= 1;
	data->map_width = ft_strlen(data->map[0]) - 1;
	close(fd);
}

void	get_player_position(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map_height)
	{
		i = 0;
		while (i < data->map_width)
		{
			if (data->map[j][i] == 'P')
			{
				data->player_posit.x = j;
				data->player_posit.y = i;
			}
			i++;
		}
		j++;
	}
	if (data->ennemy_posit.x == data->player_posit.x
		&& data->ennemy_posit.y == data->player_posit.y)
		ft_close_loss(data);
}

void	get_exit_position(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map_height)
	{
		i = 0;
		while (i < data->map_width)
		{
			if (data->map[j][i] == 'E')
			{
				data->exit_posit.x = j;
				data->exit_posit.y = i;
			}
			i++;
		}
		j++;
	}
}

void	get_ennemy_position(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map_height)
	{
		i = 0;
		while (i < data->map_width)
		{
			if (data->map[j][i] == 'B')
			{
				data->ennemy_posit.x = j;
				data->ennemy_posit.y = i;
			}
			i++;
		}
		j++;
	}
	if (data->ennemy_posit.x == data->player_posit.x
		&& data->ennemy_posit.y == data->player_posit.y)
	{
		ft_close_loss(data);
	}
}

void	get_collectible_count(t_data *data)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	j = 0;
	while (j <= data->map_width)
	{
		i = 0;
		while (i < data->map_height)
		{
			if (data->map[i][j] == 'C')
				x++;
			i++;
		}
		j++;
	}
	data->coll_counter = x;
}
