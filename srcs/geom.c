#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char    *dst;

	if (x <= S_WIDTH && x >= 0 && y <= S_HEIGHT && y >= 0)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	draw_filled_square(t_img *img, int x, int y, int size, int color)
{
	int i;

	i = 0;
	while (i < size)
	{
		draw_line(img, x, y + i, x + size, y + i, color);
		i++;
	}
}


void	draw_line(t_img *data, int start_x, int start_y, int end_x, int end_y, int color)
{
	int dx;
	int dy;
	int calc_y;
	int calc_x;

	dx = end_x - start_x;
	dy = end_y - start_y;

	if (dx > 0)
	{
		calc_x = start_x;
		while (calc_x <= end_x)
		{
			calc_y = (int)floor(start_y + (dy/dx) * (calc_x - start_x));
			my_mlx_pixel_put(data, calc_x, calc_y, color);
			calc_x++;
		}
	}
	else if (dx < 0)
	{
	calc_x = start_x;
		while (calc_x >= end_x)
		{
			calc_y = (int)floor(start_y + (dy/dx) * (calc_x - start_x));
			my_mlx_pixel_put(data, calc_x, calc_y, color);
			calc_x--;
		}
	}
	else{
		int add = dy < 0 ? +1 : -1;
		while (dy != 0)
		{
			my_mlx_pixel_put(data, start_x, start_y, color);
			start_y += add;
			dy += add;
		}
		if (dy == 0)
			my_mlx_pixel_put(data, start_x, start_y, color);
	}
}

//void	draw_horizontal_line(t_vars *vars, int x, int y, int size, int color)
//{
//	int	count;
//
//	count = 0;
//	while (count < size)
//	{
//		my_mlx_pixel_put(vars, x + count, y, color);
//		count++;
//	}
//}
//void	draw_empty_circle(t_vars *vars, int x, int y, int radius, int color)
//{
//	int	angle;
//	int	step;
//	int	xn;
//	int	yn;
//
//	angle = 0;
//	step = 1;
//
//	while (angle < 360)
//	{
//		xn = x + (radius * cos(angle));
//		yn = y + (radius * sin(angle));
//		my_mlx_pixel_put(vars, xn, yn, color);
//		angle += step;
//	}
//}

//void	draw_empty_rectangle(t_vars *vars, int x, int y, int width, int height, int color)
//{
//	draw_horizontal_line(vars, x, y, width, color);
//	draw_horizontal_line(vars, x, y + height, width, color);
//	draw_vertical_line(vars, x, y, height, color);
//	draw_vertical_line(vars, x + width, y, height, color);
//}

//void	draw_filled_rectangle(t_vars *vars, int x, int y, int width, int height, int color)
//{
//	int i;
//
//	i = 0;
//	while (i < height)
//	{
//		draw_horizontal_line(vars, x, y + i, width, color);
//		i++;
//	}
//}

//void    draw_vertical_line(t_vars *vars, int x, int y, int size, int color)
//{
//       int     count;
//
//       count = 0;
//        while (count < size)
//        {
//               my_mlx_pixel_put(vars, x, y + count, color);
//                count++;
//        }
//}