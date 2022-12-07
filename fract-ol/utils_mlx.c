#include "fractol.h"

void	init_mlx(t_mlx **mlx)
{
	*mlx = malloc(sizeof(t_mlx));
	if (!*mlx)
		return ;
	(*mlx)->mlx_ptr = mlx_init();
	(*mlx)->size_x = 1000;
	(*mlx)->size_y = 1000;
	(*mlx)->zoom_x = 0;
	(*mlx)->zoom_y = 0;
	(*mlx)->zoom = 200;
	(*mlx)->win_ptr = mlx_new_window((*mlx)->mlx_ptr, (*mlx)->size_x, (*mlx)->size_y, "Fract-ol");
	(*mlx)->img.img = mlx_new_image(mlx, (*mlx)->size_x, (*mlx)->size_y);
	(*mlx)->img.addr = mlx_get_data_addr((*mlx)->img.img, &(*mlx)->img.bits_per_pixel, &(*mlx)->img.line_length, &(*mlx)->img.endian);
}

void	fast_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	//printf("put pixel at x = %d - y %d in col %X - line_len = %d - bpp = %d\n", x, y, color, img->line_length, img->bits_per_pixel);
	*(unsigned int*)dst = color;
}
