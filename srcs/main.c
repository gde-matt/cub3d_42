#include "../includes/cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	draw_map(t_data *data, int n_rows, int n_cols, int map[n_rows][n_cols], int block_size)
{
	int	row;
	int	col;
	int	x_pos;
	int	y_pos;
	int	white;
	int	black;

	white = create_trgb(0, 255,255,255);
	black = create_trgb(0, 0, 0, 0);
	row = 0;
	while (row < n_rows)
	{
		col = 0;
		while (col < n_cols)
		{
			x_pos = col * block_size;
			y_pos = row * block_size;
			if (map[row][col] == 1)
				draw_filled_rectangle(data, x_pos, y_pos, block_size, block_size, white);
			else
				draw_filled_rectangle(data, x_pos, y_pos, block_size, block_size, black);
			col++;
		}
		row++;
	}
}

int		main(void)
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
