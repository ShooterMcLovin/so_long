/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:22:40 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/04 15:52:21 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_data	*init_data(void)
{
	static t_data	*data = NULL;
	int				i;

	if (data == NULL)
	{
		i = 0;
		data = ft_calloc(1, sizeof(t_data));
		data->map = ft_calloc(44, 80);
	}
	return (data);
}

void	init_images(t_data *data)
{
	data->images.player = mlx_texture_to_image(data->mlx,
			&data->player->texture);
	data->images.ennemy = mlx_texture_to_image(data->mlx,
			&data->ennemy->texture);
	data->images.wall = mlx_texture_to_image(data->mlx, &data->wall->texture);
	data->images.floor = mlx_texture_to_image(data->mlx,
			&data->floor->texture);
	data->images.exit = mlx_texture_to_image(data->mlx, &data->exit->texture);
	data->images.collectible = mlx_texture_to_image(data->mlx,
			&data->collectible->texture);
}

void	reset_images(t_data *data)
{
	mlx_delete_image(data->mlx, data->images.player);
	mlx_delete_image(data->mlx, data->images.ennemy);
	mlx_delete_image(data->mlx, data->images.wall);
	mlx_delete_image(data->mlx, data->images.floor);
	mlx_delete_image(data->mlx, data->images.exit);
	mlx_delete_image(data->mlx, data->images.collectible);
}

void	init_assets(t_data *data)
{
	data->player = mlx_load_xpm42("./assets/player.xpm42");
	data->ennemy = mlx_load_xpm42("./assets/bad_santa.xpm42");
	data->wall = mlx_load_xpm42("./assets/wall.xpm42");
	data->floor = mlx_load_xpm42("./assets/floor.xpm42");
	data->exit = mlx_load_xpm42("./assets/exit.xpm42");
	data->collectible = mlx_load_xpm42("./assets/candy_cane.xpm42");
	data->map_height_pixels = data->map_height * 32;
	data->map_width_pixels = data->map_width * 32;
	get_collectible_count(data);
	get_player_position(data);
	get_exit_position(data);
	get_ennemy_position(data);
}
