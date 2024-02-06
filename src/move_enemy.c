/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:16:03 by pabertha          #+#    #+#             */
/*   Updated: 2024/02/06 17:16:04 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_enemy(t_game *game, t_position former, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != EMPTY && game->map[new_y][new_x] != PLAYER)
	{
		if (game->map[former.y][former.x] == E_LEFT)
			game->map[former.y][former.x] = 'r';
		else if (game->map[former.y][former.x] == E_RIGHT)
			game->map[former.y][former.x] = 'l';
	}
	else
	{
		if (game->map[new_y][new_x] == PLAYER)
			mlx_loop_end(game->mlx);
		game->map[new_y][new_x]
			= ft_tolower(game->map[former.y][former.x]);
		game->map[former.y][former.x] = EMPTY;
		put_image(game, '0', former);
	}
	return ;
}

static void	display_enemies(t_game *game)
{
	t_position	pos;

	pos.y = 0;
	while (game->map[pos.y] != NULL)
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x] != '\0')
		{
			if (game->map[pos.y][pos.x] == 'l'
				|| game->map[pos.y][pos.x] == 'r')
			{
				game->map[pos.y][pos.x]
					= ft_toupper(game->map[pos.y][pos.x]);
				put_image(game, game->map[pos.y][pos.x], pos);
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	move_enemies(t_game *game)
{
	t_position	pos;

	pos.y = 0;
	while (game->map[pos.y] != NULL)
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x] != '\0')
		{
			if (game->map[pos.y][pos.x] == E_LEFT)
				move_enemy(game, pos, pos.x - 1, pos.y);
			else if (game->map[pos.y][pos.x] == E_RIGHT)
				move_enemy(game, pos, pos.x + 1, pos.y);
			pos.x++;
		}
		pos.y++;
	}
	display_enemies(game);
}
