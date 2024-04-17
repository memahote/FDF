/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:18:43 by memahote          #+#    #+#             */
/*   Updated: 2023/03/27 10:03:25 by memahote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_height_width(char *file_name, t_struct *data)
{
	int		fd;
	char	*line;

	data->height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit (1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), exit(1));
	data->width = ft_wordcount(line, ' ');
	while (line != NULL)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

int	fill_matrix(int *matrix_z, char *line)
{
	char	**coor;
	int		i;

	coor = ft_split(line, ' ');
	if (!coor)
		return (0);
	i = 0;
	while (coor[i])
	{
		matrix_z[i] = ft_atoi(coor[i]);
		free(coor[i]);
		i++;
	}
	free(coor);
	return (1);
}

void	malloc_width(t_struct *data)
{
	int	i;

	i = -1;
	if (!data->matrix_z)
		exit(1);
	while (++i < data->height)
	{
		data->matrix_z[i] = (int *)malloc(sizeof(int) * data->width);
		if (!data->matrix_z[i])
			ft_free_tab(data, i);
	}
}

void	read_file(char *file_name, t_struct *data)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	get_height_width(file_name, data);
	data->matrix_z = (int **)malloc(sizeof(int *) * (data->height + 1));
	malloc_width(data);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_free_tab(data, data->height - 1));
	line = get_next_line(fd);
	if (!line)
		return (close(fd), free(line), ft_free_tab(data, data->height));
	while (line != NULL)
	{
		if (fill_matrix(data->matrix_z[i], line) == 0)
			return (free(line), close(fd), ft_free_tab(data, data->height));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	data->matrix_z[i] = NULL;
}
