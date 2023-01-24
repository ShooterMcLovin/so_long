/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:06:55 by alpicard          #+#    #+#             */
/*   Updated: 2023/01/06 15:36:34 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_assets
{
	int			x;
	int			y;
	int			p;
	int			e;
	int			c;
	int			b;
}				t_assets;

typedef struct s_images
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*ennemy;

}				t_images;

typedef struct s_data
{
	mlx_t		*mlx;
	int			map_height;
	int			map_width;
	int			map_width_pixels;
	int			map_height_pixels;

	xpm_t		*wall;
	xpm_t		*floor;
	xpm_t		*player;
	xpm_t		*collectible;
	xpm_t		*exit;
	xpm_t		*ennemy;

	char		**map;
	t_pos		player_posit;
	t_pos		ennemy_posit;
	t_pos		exit_posit;

	t_assets	assets;
	t_images	images;
	int			move_counter;
	int			coll_counter;
	int			exit_flag;
}				t_data;

t_data			*init_data(void);
void			init_assets(t_data *data);
void			init_images(t_data *data);
void			reset_images(t_data *data);

void			get_map(t_data *data, char av[1]);
void			get_player_position(t_data *data);
void			get_ennemy_position(t_data *data);
void			get_exit_position(t_data *data);
void			get_collectible_count(t_data *data);

void			render_map(t_data *data);
void			render_moving_assets(int x, int y, t_data *data);

void			my_keyhook(mlx_key_data_t keydata, void *param);
void			move_ennemy(t_pos posit, t_data *data);

int				check_file_type(char *av);
void			check_map(t_data *data);
void			check_map_lines(t_data *data);
void			floodfill(char u, char v, int x, int y);
void			release(char **tab);

void			ft_close_win(t_data *data);
void			ft_close(t_data *data);
void			ft_close_loss(t_data *data);
void			ft_error_close(void);
void			error_noi(t_data *data);
#endif
