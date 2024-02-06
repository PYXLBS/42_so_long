/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:15:55 by pabertha          #+#    #+#             */
/*   Updated: 2024/02/06 17:15:56 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	write_counter(t_game *game)
{
	char	*count;

	count = ft_itoa(game->steps - 1);
	mlx_string_put(game->mlx, game->window, 116, 24, 0x0b2815, count);
	free(count);
	count = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->window, 116, 24, 0xFF0000, count);
	free(count);
}

static void	move(t_game *game, t_position former, int new_x, int new_y)
{
	t_position	new;

	new.x = new_x;
	new.y = new_y;
	if (game->map[new_y][new_x] == WALL)
		return ;
	if (game->map[new_y][new_x] == COLLECTIBLE)
		game->coins--;
	if (game->map[new_y][new_x] == EXIT)
	{
		if (game->coins == 0)
			mlx_loop_end(game->mlx);
		else
			return ;
	}
	if (game->map[new_y][new_x] == E_LEFT || game->map[new_y][new_x] == E_RIGHT)
		mlx_loop_end(game->mlx);
	game->map[new_y][new_x] = PLAYER;
	put_image(game, PLAYER, new);
	game->map[former.y][former.x] = EMPTY;
	put_image(game, EMPTY, former);
	move_enemies(game);
	game->steps++;
	write_counter(game);
	return ;
}

static void	move_player(t_game *game, int move_x, int move_y)
{
	t_position	pos;

	pos.y = 0;
	while (game->map[pos.y] != NULL)
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x] != '\0')
		{
			if (game->map[pos.y][pos.x] == PLAYER)
			{
				move(game, pos, pos.x + move_x, pos.y + move_y);
				return ;
			}
			pos.x++;
		}
		pos.y++;
	}
}

int	handle_input(int key, t_game *game)
{
	if (key == ESC)
		mlx_loop_end(game->mlx);
	else if (key == W || key == A || key == S || key == D)
	{
		if (key == W)
			move_player(game, 0, -1);
		else if (key == A)
		{
			game->player_direction = LEFT;
			move_player(game, -1, 0);
		}
		else if (key == S)
			move_player(game, 0, 1);
		else if (key == D)
		{
			game->player_direction = RIGHT;
			move_player(game, 1, 0);
		}
	}
	return (0);
}
