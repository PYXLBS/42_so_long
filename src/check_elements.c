/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:15:46 by pabertha          #+#    #+#             */
/*   Updated: 2024/02/06 17:15:47 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_walls(char **map)
{
	t_position	index;
	t_size		size;

	index.y = 0;
	size.height = 0;
	while (map[size.height] != NULL)
		size.height++;
	size.width = ft_strlen(map[0]);
	while (map[index.y] != NULL)
	{
		index.x = 0;
		while (map[index.y][index.x] != '\0')
		{
			if (index.y == 0 || index.y == size.height - 1
				|| index.x == 0 || index.x == size.width - 1)
			{
				if (map[index.y][index.x] != WALL)
					free_error_exit(map);
			}
			index.x++;
		}
		index.y++;
	}
}

void	check_collectibles(char **map)
{
	t_position	index;
	int			c;

	index.y = 0;
	c = 0;
	while (map[index.y] != NULL)
	{
		index.x = 0;
		while (map[index.y][index.x] != '\0')
		{
			if (map[index.y][index.x] == COLLECTIBLE)
				c++;
			index.x++;
		}
		index.y++;
	}
	if (c == 0)
		free_error_exit(map);
}

void	check_exit(char **map)
{
	t_position	index;
	int			e;

	index.y = 0;
	e = 0;
	while (map[index.y] != NULL)
	{
		index.x = 0;
		while (map[index.y][index.x] != '\0')
		{
			if (map[index.y][index.x] == EXIT)
				e++;
			index.x++;
		}
		index.y++;
	}
	if (e != 1)
		free_error_exit(map);
}

void	check_player(char **map)
{
	t_position	index;
	int			p;

	index.y = 0;
	p = 0;
	while (map[index.y] != NULL)
	{
		index.x = 0;
		while (map[index.y][index.x] != '\0')
		{
			if (map[index.y][index.x] == PLAYER)
				p++;
			index.x++;
		}
		index.y++;
	}
	if (p != 1)
		free_error_exit(map);
}

void	check_elements(char **map)
{
	t_position	index;

	index.y = 0;
	while (map[index.y] != NULL)
	{
		index.x = 0;
		while (map[index.y][index.x] != '\0')
		{
			if (map[index.y][index.x] != EMPTY
				&& map[index.y][index.x] != WALL
				&& map[index.y][index.x] != COLLECTIBLE
				&& map[index.y][index.x] != EXIT
				&& map[index.y][index.x] != PLAYER
				&& map[index.y][index.x] != E_LEFT
				&& map[index.y][index.x] != E_RIGHT)
				free_error_exit(map);
			index.x++;
		}
		index.y++;
	}
}
