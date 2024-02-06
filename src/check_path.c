/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:15:50 by pabertha          #+#    #+#             */
/*   Updated: 2024/02/06 17:15:51 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	flood_fill(int y, int x, char **map)
{
	if (map[y][x] == WALL || map[y][x] == E_LEFT || map[y][x] == E_RIGHT
		|| map[y][x] == PATH || map[y][x] == EXIT_OK)
		return (0);
	if (map[y][x] == EXIT)
	{
		map[y][x] = EXIT_OK;
		return (0);
	}
	else
		map[y][x] = PATH;
	if (flood_fill(y - 1, x, map) || flood_fill(y + 1, x, map)
		|| flood_fill(y, x - 1, map) || flood_fill(y, x + 1, map))
		return (1);
	return (0);
}

static int	check_e(char **map)
{
	t_position	index;

	index.y = 0;
	while (map[index.y] != NULL)
	{
		index.x = 0;
		while (map[index.y][index.x] != '\0')
		{
			if (map[index.y][index.x] == EXIT_OK)
				return (1);
			index.x++;
		}
		index.y++;
	}
	return (0);
}

static void	path(char **map)
{
	t_position	index;
	int			e;

	index.y = 0;
	e = check_e(map);
	while (map[index.y] != NULL)
	{
		index.x = 0;
		while (map[index.y][index.x] != '\0')
		{
			if (map[index.y][index.x] == COLLECTIBLE
				|| (e == '\0' && map[index.y][index.x] == EXIT))
				free_error_exit(map);
			index.x++;
		}
		index.y++;
	}
}

void	check_path(char **map)
{
	t_position	index;
	t_position	player;

	index.y = 0;
	while (map[index.y] != NULL)
	{
		index.x = 0;
		while (map[index.y][index.x] != '\0')
		{
			if (map[index.y][index.x] == PLAYER)
				player = index;
			index.x++;
		}
		index.y++;
	}
	flood_fill(player.y, player.x, map);
	path(map);
}
