/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:16:42 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/04 09:59:54 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_pos posit, t_data *data)
{
	if (posit.x - 1 == data->exit_posit.x && posit.y == data->exit_posit.y
		&& data->coll_counter == 0)
		ft_close_win(data);
	else if (data->map[posit.x - 1][posit.y] == 'C')
	{
		data->map[posit.x][posit.y] = '0';
		data->map[posit.x - 1][posit.y] = 'P';
		data->move_counter++;
		ft_printf("%d moves \n", data->move_counter);
		get_collectible_count(data);
	}
	else if (data->map[posit.x - 1][posit.y] != '1' && data->map[posit.x
			- 1][posit.y] != 'C')
	{
		data->map[posit.x][posit.y] = '0';
		data->map[posit.x - 1][posit.y] = 'P';
		data->move_counter++;
		ft_printf("%d moves \n", data->move_counter);
	}
	get_player_position(data);
	move_ennemy(data->ennemy_posit, data);
}

void	move_down(t_pos posit, t_data *data)
{
	if (posit.x + 1 == data->exit_posit.x && posit.y == data->exit_posit.y
		&& data->coll_counter == 0)
		ft_close_win(data);
	else if (data->map[posit.x + 1][posit.y] == 'C')
	{
		data->map[posit.x][posit.y] = '0';
		data->map[posit.x + 1][posit.y] = 'P';
		data->move_counter++;
		ft_printf("%d moves \n", data->move_counter);
		get_collectible_count(data);
	}
	else if (data->map[posit.x + 1][posit.y] != '1' && data->map[posit.x
			+ 1][posit.y] != 'C')
	{
		data->map[posit.x][posit.y] = '0';
		data->map[posit.x + 1][posit.y] = 'P';
		data->move_counter++;
		ft_printf("%d moves \n", data->move_counter);
	}
	get_player_position(data);
	move_ennemy(data->ennemy_posit, data);
}

void	move_left(t_pos posit, t_data *data)
{
	if (posit.x == data->exit_posit.x && posit.y - 1 == data->exit_posit.y
		&& data->coll_counter == 0)
		ft_close_win(data);
	else if (data->map[posit.x][posit.y - 1] == 'C')
	{
		data->map[posit.x][posit.y] = '0';
		data->map[posit.x][posit.y - 1] = 'P';
		data->move_counter++;
		ft_printf("%d moves \n", data->move_counter);
		get_collectible_count(data);
	}
	else if (data->map[posit.x][posit.y - 1] != '1'
			&& data->map[posit.x][posit.y - 1] != 'C')
	{
		data->map[posit.x][posit.y] = '0';
		data->map[posit.x][posit.y - 1] = 'P';
		data->move_counter++;
		ft_printf("%d moves \n", data->move_counter);
	}
	get_player_position(data);
	move_ennemy(data->ennemy_posit, data);
}

void	move_right(t_pos posit, t_data *data)
{
	if (posit.x == data->exit_posit.x && posit.y + 1 == data->exit_posit.y
		&& data->coll_counter == 0)
		ft_close_win(data);
	else if (data->map[posit.x][posit.y + 1] == 'C')
	{
		data->map[posit.x][posit.y] = '0';
		data->map[posit.x][posit.y + 1] = 'P';
		data->move_counter++;
		ft_printf("%d moves \n", data->move_counter);
		get_collectible_count(data);
	}
	else if (data->map[posit.x][posit.y + 1] != '1'
			&& data->map[posit.x][posit.y + 1] != 'C')
	{
		data->map[posit.x][posit.y] = '0';
		data->map[posit.x][posit.y + 1] = 'P';
		data->move_counter++;
		ft_printf("%d moves \n", data->move_counter);
	}
	get_player_position(data);
	move_ennemy(data->ennemy_posit, data);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = init_data();
	(void)param;
	get_player_position(data);
	get_collectible_count(data);
	get_ennemy_position(data);
	get_exit_position(data);
	if ((keydata.key == 65 || keydata.key == 263) && (keydata.action == 1
			|| keydata.action == 2))
		move_left(data->player_posit, data);
	if ((keydata.key == 87 || keydata.key == 265)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_up(data->player_posit, data);
	if ((keydata.key == 83 || keydata.key == 264)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_down(data->player_posit, data);
	if ((keydata.key == 68 || keydata.key == 262)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_right(data->player_posit, data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_close(data);
	reset_images(data);
	init_images(data);
	render_map(data);
}
