/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:44:14 by memahote          #+#    #+#             */
/*   Updated: 2023/03/27 09:58:26 by memahote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mod(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

void	zoom(t_coor *points, t_struct *data)
{
	points->x *= data->zoom;
	points->y *= data->zoom;
	points->x1 *= data->zoom;
	points->y1 *= data->zoom;
}

void	shift(t_coor *points, t_struct *data)
{
	points->x += data->shift_x;
	points->y += data->shift_y;
	points->x1 += data->shift_x;
	points->y1 += data->shift_y;
}

void	draw_menu(t_struct *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "************************");
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "*   Fil de Fer (FDF)   *");
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "************************");
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "*         Zoom:   +/-  *");
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "*         Move:    ^   *");
	mlx_string_put(mlx, win, 850, y += 10, WHITE, "*                < v > *");
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "* Switch Proj :    A   *");
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "*     Rotation:   Q/W  *");
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "*        depth:   K/J  *");
	mlx_string_put(mlx, win, 850, y += 20, WHITE, "************************");
}
