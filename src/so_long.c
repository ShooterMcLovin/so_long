/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:04:43 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/04 15:47:20 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data();
	if (ac != 2 || check_file_type(av[1]) != 1)
		ft_error_close();
	get_map(data, av[1]);
	check_map(data);
	get_map(data, av[1]);
	init_assets(data);
	data->mlx = mlx_init(data->map_width_pixels, data->map_height_pixels,
			"so_long", false);
	init_images(data);
	render_map(data);
	mlx_key_hook(data->mlx, &my_keyhook, NULL);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
