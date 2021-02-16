#include "../includes/cub3d.h"

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