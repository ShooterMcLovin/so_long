/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:41:44 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/06 15:37:26 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	floodfill(char a, char n, int x, int y)
{
	t_data	*data;

	data = init_data();
	if (data->map[x][y] == 'P' || data->map[x][y] == '0'
		|| data->map[x][y] == 'C' || data->map[x][y] == 'E'
		|| data->map[x][y] == 'B')
	{
		if (data->map[x][y] == 'C')
			data->coll_counter--;
		if (data->map[x][y] == 'E')
			data->exit_flag = 1;
		data->map[x][y] = 'D';
		floodfill(a, n, x + 1, y);
		floodfill(a, n, x - 1, y);
		floodfill(a, n, x, y - 1);
		floodfill(a, n, x, y + 1);
	}
}

int	check_file_type(char *av)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	while (av[i])
	{
		if (av[i] == '.')
			dot++;
		i++;
	}
	if (dot != 1)
		return (0);
	i = 0;
	while (av[i] != '.')
		i++;
	if (ft_strncmp(&av[i], ".ber", 5) != 0)
		return (0);
	return (1);
}

void	check_map_lines(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->map_height)
	{
		if ((int)ft_strlen(data->map[x]) - 1 != data->map_width)
		{
			ft_printf("\nMap Error, Inconsistent line lenght\n\n");
			exit(0);
		}
		x++;
	}
}

void	error_noi(t_data *data)
{
	if (data->assets.p != 1 || data->assets.e != 1 || data->assets.c < 1)
	{
		ft_printf("\n Map Item Error: ");
		if (data->assets.e != 1)
			ft_printf("wrong no of exits\n\n");
		if (data->assets.p != 1)
			ft_printf("wrong no of Player \n\n");
		if (data->assets.c < 1)
			ft_printf("wrong no of Collectibles \n\n");
		exit(0);
	}
}

void	release(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
