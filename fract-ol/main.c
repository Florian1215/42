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

int	main(void)
{
	t_mlx	mlx;

	init_mlx(&mlx);
	set_page(&mlx, 0);
	set_hook(&mlx);
	mlx_loop(mlx.mlx_ptr);
}
