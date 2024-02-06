/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:15:58 by pabertha          #+#    #+#             */
/*   Updated: 2024/02/06 17:15:59 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_size	get_size(char **map)
{
	t_size	size;

	size.height = 0;
	size.width = ft_strlen(map[0]) * 48;
	while (map[size.height] != NULL)
		size.height++;
	size.height = size.height * 48;
	if (size.height < 144 || size.width < 144
		|| size.height > 1008 || size.width > 1968)
		free_error_exit(map);
	return (size);
}

static int	count_collectibles(t_game *game)
{
	t_position	index;
	int			c;

	index.y = 0;
	c = 0;
	while (game->map[index.y] != NULL)
	{
		index.x = 0;
		while (game->map[index.y][index.x] != '\0')
		{
			if (game->map[index.y][index.x] == COLLECTIBLE)
				c++;
			index.x++;
		}
		index.y++;
	}
	return (c);
}

void	get_info(t_game *game)
{
	game->size_map = get_size(game->map);
	game->coins = count_collectibles(game);
}

char	**get_content(int fd)
{
	char	*line;
	char	*stash;
	char	**result;

	line = "";
	stash = NULL;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			stash = ft_strjoin_get_next_line(stash, line);
			if (stash == NULL)
			{
				free(line);
				return (NULL);
			}
		}
		free(line);
	}
	result = ft_split(stash, '\n');
	free(stash);
	return (result);
}

char	**get_map(char *map)
{
	int		fd;
	char	**result;

	fd = open(map, O_RDONLY);
	result = get_content(fd);
	close(fd);
	return (result);
}
