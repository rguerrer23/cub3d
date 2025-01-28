/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:17:38 by rguerrer          #+#    #+#             */
/*   Updated: 2025/01/28 11:40:59 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->map = NULL;
	map->input = NULL;
	map->p_x = -1;
	map->p_y = -1;
	map->w_map = 0;
	map->h_map = 0;
	map->init_view = 0;
}

void	init_config(t_config *config)
{
	config->no_texture_path = NULL;
	config->so_texture_path = NULL;
	config->we_texture_path = NULL;
	config->ea_texture_path = NULL;
	config->no_texture = NULL;
	config->so_texture = NULL;
	config->we_texture = NULL;
	config->ea_texture = NULL;
	config->floor_color[0] = -1;
	config->floor_color[1] = -1;
	config->floor_color[2] = -1;
	config->ceiling_color[0] = -1;
	config->ceiling_color[1] = -1;
	config->ceiling_color[2] = -1;
}

void	init_cub(t_cub *cub)
{
	cub->map = ft_calloc(1, sizeof(t_map));
	cub->ply = calloc(1, sizeof(t_player));
	cub->ray = calloc(1, sizeof(t_ray));
	init_map(cub->map);
	init_config(&cub->config);
}
