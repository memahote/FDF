/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:05:20 by memahote          #+#    #+#             */
/*   Updated: 2023/03/29 12:44:17 by memahote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_struct	data;
	int			len;

	len = ft_strlen(argv[1]);
	if (argc == 2 && ft_strnstr(argv[1], ".fdf", len))
	{
		ft_bzero(&data, sizeof (t_struct));
		read_file(argv[1], &data);
		init_data(&data);
		draw(&data);
		mlx_hook(data.win_ptr, 17, (1l << 0), close_window, &data);
		mlx_hook(data.win_ptr, 2, (1L << 0), deal_key, &data);
		mlx_mouse_hook(data.win_ptr, mouse, &data);
		mlx_loop(data.mlx_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		free(data.image);
	}
	return (0);
}
