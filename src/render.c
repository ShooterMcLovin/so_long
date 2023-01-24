/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:38:34 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/06 12:22:33 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_moving_assets(int x, int y, t_data *data)
{
	if (data->map[x][y] == 'B')
	{
		mlx_image_to_window(data->mlx, data->images.floor, y * 32, x * 32);
		mlx_image_to_window(data->mlx, data->images.ennemy, y * 32, x * 32);
	}
	else if (data->map[x][y] == 'P')
	{
		mlx_image_to_window(data->mlx, data->images.floor, y * 32, x * 32);
		mlx_image_to_window(data->mlx, data->images.player, y * 32, x * 32);
	}
}

void	render_assets(int x, int y, t_data *data)
{
	if (data->map[x][y] == '1')
		mlx_image_to_window(data->mlx, data->images.wall, y * 32, x * 32);
	else if (data->map[x][y] == 'C')
	{
		mlx_image_to_window(data->mlx, data->images.floor, y * 32, x * 32);
		mlx_image_to_window(data->mlx, data->images.collectible, y * 32, x
			* 32);
	}
	else
		mlx_image_to_window(data->mlx, data->images.floor, y * 32, x * 32);
}

void	render_exit(t_data *data)
{
	mlx_image_to_window(data->mlx, data->images.exit, data->exit_posit.y * 32,
		data->exit_posit.x * 32);
}

void	render_map(t_data *data)
{
	int		x;
	int		y;
	char	*str;

	str = malloc(5);
	if (!str)
		return ;
	y = 0;
	while (y < data->map_width)
	{
		x = 0;
		while (x < data->map_height)
		{
			render_assets(x, y, data);
			render_moving_assets(x, y, data);
			x++;
		}
		y++;
	}
	render_exit(data);
	str = ft_itoa(data->move_counter);
	mlx_put_string(data->mlx, "Number of moves: ", 1, 0);
	mlx_put_string(data->mlx, str, 165, 0);
	free(str);
	str = NULL;
}
