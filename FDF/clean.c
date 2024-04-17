/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:37:15 by memahote          #+#    #+#             */
/*   Updated: 2023/03/01 10:37:15 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_struct *data)
{
	free_all(data);
	return (0);
}

void	ft_free_tab(t_struct *data, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(data->matrix_z[i++]);
	free(data->matrix_z);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_FAILURE);
}

void	free_all(t_struct *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->matrix_z[i++]);
	free(data->matrix_z);
	if (data->mlx_ptr && data->image)
		mlx_destroy_image(data->mlx_ptr, data->image);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->image);
	exit(0);
}
