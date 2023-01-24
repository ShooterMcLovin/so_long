/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:23:39 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/06 15:37:03 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_valid_char(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map_width)
	{
		i = 0;
		while (i < data->map_height)
		{
			if (data->map[i][j] == 'E' || data->map[i][j] == 'P'
				|| data->map[i][j] == 'C' || data->map[i][j] == '1'
				|| data->map[i][j] == '0' || data->map[i][j] == '\n'
				|| data->map[i][j] == 'B')
			{
				i++;
			}
			else
			{
				ft_printf("\nMap Error: Invalid Map Input\n\n");
				exit(0);
			}
		}
		j++;
	}
}

void	check_number_of_items(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_height)
	{
		y = 0;
		while (y < data->map_width)
		{
			if (data->map[x][y] == 'E')
				data->assets.e++;
			if (data->map[x][y] == 'P')
				data->assets.p++;
			if (data->map[x][y] == 'C')
				data->assets.c++;
			if (data->map[x][y] == 'B')
				data->assets.b++;
			y++;
		}
		x++;
	}
	error_noi(data);
}

int	check_walls_h(t_data *data)
{
	int	x;
	int	y;
	int	r;

	r = 1;
	x = 0;
	y = 0;
	while (y < data->map_width)
	{
		if (data->map[0][y] != '1')
			r = 0;
		y++;
	}
	y = 0;
	x = data->map_height - 1;
	while (y < data->map_width)
	{
		if (data->map[x][y] != '1')
			r = 0;
		y++;
	}
	return (r);
}

int	check_walls_v(t_data *data)
{
	int	x;
	int	y;
	int	r;

	r = 1;
	x = 0;
	y = 0;
	while (x < data->map_height)
	{
		if (data->map[x][0] != '1')
			r = 0;
		x++;
	}
	x = 0;
	y = data->map_width - 1;
	while (x < data->map_height)
	{
		if (data->map[x][y] != '1')
			r = 0;
		x++;
	}
	return (r);
}

void	check_map(t_data *data)
{
	int	x;
	int	y;

	check_number_of_items(data);
	get_player_position(data);
	get_exit_position(data);
	x = data->player_posit.x;
	y = data->player_posit.y;
	check_valid_char(data);
	check_map_lines(data);
	get_collectible_count(data);
	if (check_walls_v(data) == 0 || check_walls_h(data) == 0)
	{
		ft_printf("\nMap Error: Invalid Map\n\n");
		exit(0);
	}
	floodfill('0', '@', x, y);
	if (data->coll_counter > 0 || data->exit_flag != 1)
	{
		ft_printf("\nMap Error: Invalid Path\n\n");
		exit(0);
	}
	get_collectible_count(data);
	release(data->map);
	data->map = ft_calloc(data->map_height, sizeof(char *));
}
