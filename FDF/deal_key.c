/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:16:16 by memahote          #+#    #+#             */
/*   Updated: 2023/03/27 09:34:25 by memahote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse(int mouse, int x, int y, t_struct *t_data)
{
	mlx_clear_window(t_data->mlx_ptr, t_data->win_ptr);
	if (mouse == 5)
		t_data->zoom += 1;
	if (mouse == 4)
	{
		if (t_data->zoom < 5)
			t_data->zoom = 5;
		t_data->zoom -= 1;
	}
	if (mouse == 1)
	{
		t_data->shift_x = x;
		t_data->shift_y = y;
	}
	draw(t_data);
	return (0);
}

void	key_helper(int key, t_struct *t_data)
{
	if (key == 97)
	{
		if (t_data->iso == 1)
			t_data->iso -= 1;
		else if (t_data->iso == 0)
			t_data->iso += 1;
	}
	if (key == 113)
		t_data->angle_x += 0.2;
	if (key == 119)
		t_data->angle_y += 0.2;
	if (key == 107)
		t_data->depth += 1;
	if (key == 106)
		t_data->depth -= 1;
	if (key == 65453)
	{
		if (t_data->zoom < 10)
			t_data->zoom = 10;
		t_data->zoom -= 5;
	}
	if (key == 65451)
		t_data->zoom += 5;
}

int	deal_key(int key, t_struct *t_data)
{
	mlx_clear_window(t_data->mlx_ptr, t_data->win_ptr);
	if (key == 65364)
		t_data->shift_y += 10;
	if (key == 65362)
		t_data->shift_y -= 10;
	if (key == 65361)
		t_data->shift_x -= 10;
	if (key == 65363)
		t_data->shift_x += 10;
	if (key == 65307)
		ft_free_tab(t_data, t_data->height);
	key_helper(key, t_data);
	draw(t_data);
	return (0);
}
