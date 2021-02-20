#include "../includes/cub3d.h"

int		close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return 0;
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	draw_map(t_img *img, int n_rows, int n_cols, int map[n_rows][n_cols], int block_size)
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
				draw_filled_rectangle(img, x_pos, y_pos, block_size, block_size, white);
			else
				draw_filled_rectangle(img, x_pos, y_pos, block_size, block_size, black);
			col++;
		}
		row++;
	}
}

void	start_player(t_vars *vars)
{
	vars->player.coord.x = 50;
	vars->player.coord.y = 50;
	vars->player.size = 4;
	vars->player.turnDirection = PI/2;
	vars->player.walkSpeed = 10;
	vars->player.turnSpeed = 45 * (PI/2);
}

int close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	exit(1);
	return (0);
}

int keyPress(int keycode, t_vars *vars)
{
    if (keycode == ESC)
		close_window(vars);
    if (keycode == UP)
		vars->player.walkDirection = 1;
    if (keycode == DOWN)
		vars->player.walkDirection = -1;
	vars->update =  1;
	return (0);
}

int keyRelease(int keycode, t_vars *vars)
{
    if (keycode == UP)
		vars->player.walkDirection = 0;
	if (keycode == DOWN)
		vars->player.walkDirection = 0;
	vars->update =  1;
	return (0);
}

int renderPlayer(t_vars *vars)
{
	draw_filled_rectangle(vars, vars->player.coord.x, vars->player.coord.y,
	vars->player.size, vars->player.size, create_trgb(0, 255, 0, 0));
	return(0);
}

int movePlayer(t_vars *vars)
{
	float nx = vars->player.coord.x + vars->player.walkDirection * 5;
	float ny = vars->player.coord.y + vars->player.walkDirection * 5;

	vars->player.coord.x = nx;
	vars->player.coord.y = ny;

	return(0);
}

int	print_map(t_vars *vars)
{
	int	map[N_ROWS][N_COLS] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,0,0,1,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	};

	draw_map(vars->img.img, N_ROWS, N_COLS, map, BLOCK_SIZE);
	renderPlayer(vars);

	return (0);
}

int update(t_vars *vars)
{
	movePlayer(vars);
	return (0);

}

int game(t_vars *vars)
{
	if (vars->update)
	{
		update(vars);
		print_map(vars);
	}
	return (0);
}

int		main(void)
{

	t_vars	vars;

	start_player(&vars.player);
	vars.update = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, S_WIDTH, S_HEIGHT, "Hello Word");
	vars.img.img = mlx_new_image(vars.mlx, S_WIDTH, S_HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);

	mlx_hook(vars.win, 2, 1L<<0, keyPress, &vars);
	mlx_hook(vars.win, 3, 1L<<1, keyRelease, &vars);
	mlx_hook(vars.win, 33, 1L<<17, close, &vars);
	mlx_loop_hook(vars.mlx, game, &vars);
	
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
}