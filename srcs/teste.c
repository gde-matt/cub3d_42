#include "mlx.h"
#include <stdio.h>
#include <math.h>

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

	i = 0;
	while (i < height)
	{
		draw_horizontal_line(data, x, y + i, width, color);
		i++;
	}
}

void	draw_empty_rectangle(t_data *data, int x, int y, int width, int height, int color)
{
	draw_horizontal_line(data, x, y, width, color);
	draw_horizontal_line(data, x, y + height, width, color);
	draw_vertical_line(data, x, y, height, color);
	draw_vertical_line(data, x + width, y, height, color);
}

void	draw_empty_circle(t_data *data, int x, int y, int radius, int color)
{
	int	angle;
	int	step;
	int	xn;
	int	yn;

	angle = 0;
	step = 1;

	while (angle < 360)
	{
		xn = x + (radius * cos(angle));
		yn = y + (radius * sin(angle));
		my_mlx_pixel_put(data, xn, yn, color);
		angle += step;
	}
	
}

void	draw_map(t_data *data, int n_rows, int n_cols, int map[n_rows][n_cols], int block_size)
{
	int	row;
	int	col;
	int	x_pos;
	int	y_pos;

	row = 0;
	while (row < n_rows)
	{
		col = 0;
		while (col < n_cols)
		{
			x_pos = col * block_size;
			y_pos = row * block_size;
			if (map[row][col] == 1)
				draw_filled_rectangle(data, x_pos, y_pos, block_size, block_size, 0x00FFFFFF);
			else
				draw_filled_rectangle(data, x_pos, y_pos, block_size, block_size, 0x00000000);
			col++;
		}
		row++;
	}
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	int	map[7][10] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,0,0,1,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	};

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 420, 294, "Hello Word");
	img.img = mlx_new_image(mlx, 420, 294);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	//my_mlx_pixel_put(&img,  10, 10, 0x00FFFF00);
	//draw_horizontal_line(&img, 100, 250, 150, 0x00FF0000);
	//draw_vertical_line(&img, 100, 250, 150, 0x000000FF);
	//draw_filled_rectangle(&img, 20, 20, 30, 50, 0x0000FF00);
	//draw_empty_rectangle(&img, 60, 20, 50, 80, 0x0000FF00);
	//draw_empty_circle(&img, 300, 100, 50, 0x00FF0000);

	draw_map(&img, 7, 10, map, 42);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
}
