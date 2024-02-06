/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:16:01 by pabertha          #+#    #+#             */
/*   Updated: 2024/02/06 17:16:35 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_exit(t_game *game)
{
	free_all(game);
	exit(1);
}

static void	*secure_map(t_game *game, char *ber)
{
	void	*map;

	map = get_map(ber);
	if (map == NULL)
		free_exit(game);
	return (map);
}

static void	secure_window_mlx(t_game *game, char *title)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		free_exit(game);
	game->window = mlx_new_window(game->mlx, game->size_map.width,
			game->size_map.height, title);
	if (game->window == NULL)
		free_exit(game);
}

static void	*secure_img(t_game *game, char *path, t_img *image)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &image->width, &image->height);
	if (img == NULL)
		free_exit(game);
	return (img);
}

void	initialize(t_game *game, char *ber)
{
	game->player_direction = RIGHT;
	game->steps = 0;
	game->map = secure_map(game, ber);
	get_info(game);
	secure_window_mlx(game, "tan_largo");
	game->element.cd.img = secure_img(game, "img/cd.xpm", &game->element.cd);
	game->element.coins.img = secure_img(game, "img/coins.xpm",
			&game->element.coins);
	game->element.grass.img = secure_img(game, "img/grass.xpm",
			&game->element.grass);
	game->element.guitar_left.img = secure_img(game, "img/guitar_left.xpm",
			&game->element.guitar_left);
	game->element.guitar_right.img = secure_img(game, "img/guitar_right.xpm",
			&game->element.guitar_right);
	game->element.scooter_left.img = secure_img(game, "img/scooter_left.xpm",
			&game->element.scooter_left);
	game->element.scooter_right.img = secure_img(game, "img/scooter_right.xpm",
			&game->element.scooter_right);
	game->element.tv_wall.img = secure_img(game, "img/tv_wall.xpm",
			&game->element.tv_wall);
	game->element.wall.img = secure_img(game, "img/wall.xpm",
			&game->element.wall);
}
