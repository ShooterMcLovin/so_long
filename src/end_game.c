/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:20:50 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/04 09:58:33 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_close_win(t_data *data)
{
	ft_printf("\nYou Won in %d moves\n", data->move_counter + 1);
	mlx_terminate(data->mlx);
	exit(0);
}

void	ft_close_loss(t_data *data)
{
	ft_printf("\nYou lost!! \n\n");
	mlx_terminate(data->mlx);
	exit(0);
}

void	ft_error_close(void)
{
	ft_printf("\nError: Invalid Map\n\n");
	exit(0);
}

void	ft_close(t_data *data)
{
	ft_printf("\nYou quit after %d moves\n", data->move_counter);
	ft_printf("collectibles remaining: %d\n\n", data->coll_counter);
	mlx_terminate(data->mlx);
	exit(0);
}
