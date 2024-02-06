/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:15:52 by pabertha          #+#    #+#             */
/*   Updated: 2024/02/06 17:15:53 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_image_bonus(t_game *game, char character, t_position pos)
{
	if (character == E_LEFT)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->element.scooter_left.img,
			pos.x * 48, pos.y * 48);
	}
	else if (character == E_RIGHT)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->element.scooter_right.img,
			pos.x * 48, pos.y * 48);
	}
	else if (character == WALL && pos.x == 2 && pos.y == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->element.tv_wall.img, pos.x * 48, pos.y * 48);
}

void	put_image(t_game *game, char character, t_position pos)
{
	if (character == EMPTY)
		mlx_put_image_to_window(game->mlx, game->window,
			game->element.grass.img, pos.x * 48, pos.y * 48);
	else if (character == WALL)
		mlx_put_image_to_window(game->mlx, game->window, game->element.wall.img,
			pos.x * 48, pos.y * 48);
	else if (character == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->window,
			game->element.coins.img, pos.x * 48, pos.y * 48);
	else if (character == EXIT)
		mlx_put_image_to_window(game->mlx, game->window, game->element.cd.img,
			pos.x * 48, pos.y * 48);
	else if (character == PLAYER)
	{
		if (game->player_direction == RIGHT)
			mlx_put_image_to_window(game->mlx, game->window,
				game->element.guitar_right.img, pos.x * 48,
				pos.y * 48);
		else
			mlx_put_image_to_window(game->mlx, game->window,
				game->element.guitar_left.img, pos.x * 48,
				pos.y * 48);
	}
	put_image_bonus(game, character, pos);
}

int	display_map(t_game *game)
{
	t_position	pos;

	pos.y = 0;
	while (game->map[pos.y] != NULL)
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x] != '\0')
		{
			put_image(game, game->map[pos.y][pos.x], pos);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
