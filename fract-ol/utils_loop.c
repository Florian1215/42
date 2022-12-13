#include "fractol.h"

int	loop(t_mlx *mlx)
{
	if (mlx->launch)
	{
		edit_c(mlx, mlx->c.y < -0.4 ? 0.07 : 0.03, &mlx->c.y);
		if (mlx->c.y > 0)
		{
			edit_c(mlx, -mlx->c.y, &mlx->c.y);
			mlx->launch = 0;
		}
	}
	else if (mlx->in_menu)
	{
		if (mlx->hover.value >= 0.75 || mlx->prev_hover.value < 1)
		{
			if (mlx->hover.value >= 0.75)
				mlx->hover.value -= (mlx->hover.value >= 0.90 ? 0.02 : 0.06);
			if (mlx->prev_hover.value < 1)
				mlx->prev_hover.value += (mlx->prev_hover.value <= 0.90 ? 0.03 : 0.06);
			set_menu(mlx);
		}
	}
	return (1);
}
