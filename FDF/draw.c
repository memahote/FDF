/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:58:07 by memahote          #+#    #+#             */
/*   Updated: 2023/03/27 09:51:44 by memahote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_coor *points, t_struct *data, int z, int z1)
{
	points->x = (points->x - points->y) * cos(data->angle_x);
	points->y = (points->x + points->y) * sin(data->angle_y) - z;
	points->x1 = (points->x1 - points->y1) * cos(data->angle_x);
	points->y1 = (points->x1 + points->y1) * sin(data->angle_y) - z1;
}

void	choose_color(t_coor *points, t_struct *data)
{
	if (points->z || points->z1)
		data->color = RED;
	else
		data->color = WHITE;
}

void	bresenham(t_coor points, t_struct *data)
{
	float	x_steps;
	float	y_steps;
	int		big;

	points.z = data->matrix_z[(int)points.y][(int)points.x] * data->depth;
	points.z1 = data->matrix_z[(int)points.y1][(int)points.x1] * data->depth;
	zoom(&points, data);
	if (data->iso == 1)
		isometric(&points, data, points.z, points.z1);
	shift(&points, data);
	choose_color(&points, data);
	x_steps = points.x1 - points.x;
	y_steps = points.y1 - points.y;
	big = max(mod(x_steps), mod(y_steps));
	x_steps /= big;
	y_steps /= big;
	while ((int)(points.x - points.x1) || (int)(points.y - points.y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, points.x, points.y, \
				data->color);
		points.x += x_steps;
		points.y += y_steps;
	}
}

void	algo(t_coor points, t_struct *data, int status)
{
	if (status == 0)
	{
		points.x1 = points.x + 1;
		points.y1 = points.y;
	}
	if (status == 1)
	{
		points.y1 = points.y + 1;
		points.x1 = points.x;
	}
	bresenham(points, data);
}

void	draw(t_struct *data)
{
	t_coor	points;

	points.y = 0;
	draw_menu(data);
	while (points.y < data->height)
	{
		points.x = 0;
		while (points.x < data->width)
		{
			if (points.x < data->width - 1)
			{
				algo(points, data, 0);
			}
			if (points.y < data->height - 1)
			{
				algo(points, data, 1);
			}
			points.x++;
		}
		points.y++;
	}
}
