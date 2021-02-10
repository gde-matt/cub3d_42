#include "mlx.h"
#include <stdio.h>

typedef struct  s_data 
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_horizontal_line(t_data *data, int x, int y, int size, int color)
{
	int	count;

	count = 0;
	while (count < size)
	{
		my_mlx_pixel_put(data, x + count, y, color);
		count++;
	}
}

void    draw_vertical_line(t_data *data, int x, int y, int size, int color)
{
        int     count;

        count = 0;
        while (count < size)
        {
                my_mlx_pixel_put(data, x, y + count, color);
                count++;
        }
}

void	draw_filled_rectangle(t_data *data, int x, int y, int width, int height, int color)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			my_mlx_pixel_put(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}	



int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello Word");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 10, 10, 0x00FFFF00);
	draw_horizontal_line(&img, 100, 250, 150, 0x00FF0000);
	draw_vertical_line(&img, 100, 250, 150, 0x000000FF);
	draw_filled_rectangle(&img, 20, 20, 30, 50, 0x0000FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
}
