/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:04:55 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/04 14:21:30 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_ennemy_v(t_pos posit, t_data *data)
{
	int	x;

	get_ennemy_position(data);
	x = data->player_posit.x - data->ennemy_posit.x;
	if (x < 0)
	{
		if (data->map[data->ennemy_posit.x - 1][data->ennemy_posit.y] != '1'
			&& data->map[data->ennemy_posit.x - 1][data->ennemy_posit.y] != 'C'
			&& data->map[data->ennemy_posit.x - 1][data->ennemy_posit.y] != 'B')
		{
			data->map[posit.x][posit.y] = '0';
			data->map[posit.x - 1][posit.y] = 'B';
		}
	}
	else if (x > 0)
	{
		if (data->map[data->ennemy_posit.x + 1][data->ennemy_posit.y] != '1'
			&& data->map[data->ennemy_posit.x + 1][data->ennemy_posit.y] != 'C'
			&& data->map[data->ennemy_posit.x + 1][data->ennemy_posit.y] != 'B')
		{
			data->map[posit.x][posit.y] = '0';
			data->map[posit.x + 1][posit.y] = 'B';
		}
	}
}

void	move_ennemy_l(t_pos posit, t_data *data)
{
	int	y;

	get_ennemy_position(data);
	y = data->player_posit.y - data->ennemy_posit.y;
	if (y < 0)
	{
		if (data->map[data->ennemy_posit.x][data->ennemy_posit.y - 1] != '1'
			&& data->map[data->ennemy_posit.x][data->ennemy_posit.y - 1] != 'C'
			&& data->map[data->ennemy_posit.x][data->ennemy_posit.y - 1] != 'B')
		{
			data->map[posit.x][posit.y] = '0';
			data->map[posit.x][posit.y - 1] = 'B';
		}
	}
	else if (y > 0)
	{
		if (data->map[data->ennemy_posit.x][data->ennemy_posit.y + 1] != '1'
			&& data->map[data->ennemy_posit.x][data->ennemy_posit.y + 1] != 'C'
			&& data->map[data->ennemy_posit.x][data->ennemy_posit.y + 1] != 'B')
		{
			data->map[posit.x][posit.y] = '0';
			data->map[posit.x][posit.y + 1] = 'B';
		}
	}
}

int	abs_val(int nb)
{
	if (nb < 0)
		nb *= (-1);
	return (nb);
}

void	move_ennemy(t_pos posit, t_data *data)
{
	if (data->ennemy_posit.x > 0 && data->ennemy_posit.y > 0)
	{
		if (abs_val(data->player_posit.x
				- posit.x) <= abs_val(data->player_posit.y - posit.y))
			move_ennemy_l(data->ennemy_posit, data);
		else if (abs_val(data->player_posit.x
				- posit.x) >= abs_val(data->player_posit.y - posit.y))
			move_ennemy_v(data->ennemy_posit, data);
		get_ennemy_position(data);
	}
}
