/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:00:25 by rguerrer          #+#    #+#             */
/*   Updated: 2025/02/06 13:04:16 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_map(char **input)
{
	int		i;
	int		j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j] == ' ')
			j++;
		if (input[i][j] && input[i][j] != '\n' &&
			ft_strstr(input[i], "NO") == NULL &&
			ft_strstr(input[i], "SO") == NULL &&
			ft_strstr(input[i], "WE") == NULL &&
			ft_strstr(input[i], "EA") == NULL &&
			ft_strstr(input[i], "F") == NULL &&
			ft_strstr(input[i], "C") == NULL)
			return (&input[i]);
		i++;
	}
	ft_putstr_fd("Error\nInvalid map\n", 2);
	return (NULL);
}

int	ft_valid_elements(char **input)
{
	int	i;
	int	count;
	int	elements[6];

	i = -1;
	count = 0;
	while (++i < 6)
		elements[i] = 0;
	i = 0;
	while (input[i])
	{
		if (ft_check_elements(input[i], elements) == 0)
			count++;
		else if (input[i][0] != '\n' && count != 6)
			break ;
		i++;
	}
	count = elements[0] + elements[1] + elements[2] + elements[3]
		+ elements[4] + elements[5];
	if (elements[0] > 1 || elements[1] > 1 || elements[2] > 1
		|| elements[3] > 1 || elements[4] > 1 || elements[5] > 1)
		return (ft_putstr_fd("Error\nDuplicate elements\n", 2), 1);
	if (count != 6)
		return (ft_putstr_fd("Error\nMissing elements\n", 2), 1);
	return (0);
}

int	ft_is_valid_number(const char *str)
{
	int	num;
	int	i;

	while (*str == ' ')
		str++;
	if (*str == '\0' || *str == '\n')
		return (0);
	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	remove_non_printable((char *)str);
	if (str[i] != '\0')
		return (0);
	num = ft_atoi(str);
	return (num >= 0 && num <= 255);
}

int	ft_valid_rgb(char **input)
{
	int		i;
	int		j;
	char	**rgb;

	i = -1;
	while (input[++i])
	{
		j = 0;
		while (input[i][j] == ' ')
			j++;
		if (ft_strchr("FC", input[i][j]))
		{
			rgb = ft_split(&input[i][++j], ',');
			if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
				return (ft_putstr_fd("Error\nInvalid RGB format\n", 2),
					ft_free_split(rgb), 1);
			if (!ft_is_valid_number(rgb[0]) || !ft_is_valid_number(rgb[1])
				|| !ft_is_valid_number(rgb[2]))
				return (ft_putstr_fd("Error\nRGB values out of range\n", 2),
					ft_free_split(rgb), 1);
			ft_free_split(rgb);
		}
	}
	return (0);
}

int	ft_check(t_cub *cub)
{
	if (ft_valid_elements(cub->map->input) == 1)
		return (1);
	if (ft_valid_rgb(cub->map->input) == 1)
		return (1);
	cub->map->map = ft_map(cub->map->input);
	if (!cub->map->map)
		return (1);
	ft_quit_newline(cub->map->map);
	if (ft_check_map(cub->map->map) == 1)
		return (1);
	return (0);
}
