/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:36:42 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/05 14:48:22 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	(void)ac;
	(void)av;
	init_mlx(&mlx);
	if (!mlx)
		return (1);
	set_menu(mlx);
	mlx_key_hook(mlx->win_ptr, key_event, mlx);
	mlx_hook(mlx->win_ptr, 17, 0L, close, mlx);
	mlx_hook(mlx->win_ptr, 4, (1L << 2), mouse_event, mlx);
	mlx_loop(mlx->mlx_ptr);
}
