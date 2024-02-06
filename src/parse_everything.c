/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_everything.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:16:06 by pabertha          #+#    #+#             */
/*   Updated: 2024/02/06 17:16:07 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_extension(char *av_1)
{
	int		len_av_1;

	len_av_1 = ft_strlen(av_1);
	if (len_av_1 >= 4)
	{
		if (av_1[len_av_1 - 1] != 'r' && av_1[len_av_1 - 2] != 'e'
			&& av_1[len_av_1 - 3] != 'b' && av_1[len_av_1 - 4] != '.')
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
}

void	free_error_exit(char **map)
{
	free_map(map);
	ft_printf("Error\n");
	exit(1);
}

static void	check_shape(char **map)
{
	t_position	index;
	int			len_map;

	index.y = 0;
	index.x = 0;
	len_map = ft_strlen(map[0]);
	while (map[index.y] != NULL)
	{
		while (map[index.y][index.x] != '\0')
			index.x++;
		if (index.x != len_map)
			free_error_exit(map);
		index.x = 0;
		index.y++;
	}
}

static void	check_everything(char **map)
{
	check_shape(map);
	check_walls(map);
	check_elements(map);
	check_player(map);
	check_exit(map);
	check_collectibles(map);
	get_size(map);
	check_path(map);
}

void	parse_everything(char **av)
{
	int		fd;
	char	**map;

	check_extension(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	map = get_content(fd);
	if (map == NULL)
	{
		ft_printf("Error\n");
		close(fd);
		exit(1);
	}
	check_everything(map);
	free_map(map);
	close(fd);
}
