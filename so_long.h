/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:16:16 by pabertha          #+#    #+#             */
/*   Updated: 2024/02/06 17:16:17 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define E_LEFT 'L'
# define E_RIGHT 'R'
# define PATH 'X'
# define EXIT_OK 'e'

# include "libs/libft/libft.h"
# include "libs/mlx/mlx.h"

typedef enum e_direction
{
	LEFT,
	RIGHT
}				t_direction;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct s_element
{
	t_img	grass;
	t_img	wall;
	t_img	coins;
	t_img	cd;
	t_img	guitar_left;
	t_img	guitar_right;
	t_img	scooter_left;
	t_img	scooter_right;
	t_img	tv_wall;
}				t_element;

typedef struct s_size
{
	int	width;
	int	height;
}				t_size;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	t_size		size_map;
	t_element	element;
	int			steps;
	int			coins;
	t_direction	player_direction;
	t_direction	scooter_direction;
}				t_game;

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

void	check_walls(char **map);
void	check_collectibles(char **map);
void	check_exit(char **map);
void	check_player(char **map);
void	check_elements(char **map);

void	check_path(char **map);

void	put_image(t_game *game, char character, t_position pos);
int		display_map(t_game *game);

int		handle_input(int key, t_game *game);

t_size	get_size(char **map);
void	get_info(t_game *game);
char	**get_content(int fd);
char	**get_map(char *map);

void	initialize(t_game *game, char *ber);

void	move_enemies(t_game *game);

void	free_error_exit(char **map);
void	parse_everything(char **av);

void	free_map(char **map);
void	free_all(t_game *game);

int		main(int ac, char **av);

#endif
