/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:16:09 by pabertha          #+#    #+#             */
/*   Updated: 2024/02/06 17:16:10 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	secure_destroy_img(void *mlx, void *img)
{
	if (img != NULL)
		mlx_destroy_image(mlx, img);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	if (map != NULL)
		free(map);
}

static void	secure_destroy_window_display(void *mlx, void *window)
{
	if (window != NULL)
		mlx_destroy_window(mlx, window);
	if (mlx != NULL)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}
}

void	free_all(t_game *game)
{
	secure_destroy_img(game->mlx, game->element.cd.img);
	secure_destroy_img(game->mlx, game->element.coins.img);
	secure_destroy_img(game->mlx, game->element.grass.img);
	secure_destroy_img(game->mlx, game->element.guitar_left.img);
	secure_destroy_img(game->mlx, game->element.guitar_right.img);
	secure_destroy_img(game->mlx, game->element.scooter_left.img);
	secure_destroy_img(game->mlx, game->element.scooter_right.img);
	secure_destroy_img(game->mlx, game->element.tv_wall.img);
	secure_destroy_img(game->mlx, game->element.wall.img);
	free_map(game->map);
	secure_destroy_window_display(game->mlx, game->window);
}
