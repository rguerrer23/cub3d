/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:45:56 by rguerrer          #+#    #+#             */
/*   Updated: 2025/01/28 11:35:53 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(t_cub *cub) 		// exit the game
{
	free_cub(cub);
	mlx_delete_image(cub->mlx_p, cub->img); // delete the image
	mlx_close_window(cub->mlx_p); // close the window
	mlx_terminate(cub->mlx_p); // terminate the mlx pointer
	printf("Game closed\n"); // print the message
	exit(0); // exit the game
}

int main(int ac, char **av)
{
	t_cub cub;

	if (ac != 2 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
	{
		ft_putstr_fd("Error\nInvalid arguments\n", 2);
		return (1);
	}
	else
	{
		if (parse_cub(&cub, av[1]) == 1)
			return (1);
		printf("Running game\n");
        start_the_game(&cub);
		printf("Game over\n");
	}
	return (0);
}
