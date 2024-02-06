/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:16:13 by pabertha          #+#    #+#             */
/*   Updated: 2024/02/06 17:16:14 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Error\n");
		exit(1);
	}
	parse_everything(av);
	initialize(&game, av[1]);
	display_map(&game);
	mlx_key_hook(game.window, handle_input, &game);
	mlx_hook(game.window, 17, 0, mlx_loop_end, game.mlx);
	mlx_loop(game.mlx);
	free_all(&game);
	return (0);
}
