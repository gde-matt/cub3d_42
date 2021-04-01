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

void	draw_map(t_img *img, int n_rows, int n_cols, int map[n_rows][n_cols])
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
			x_pos = col * BLOCK_SIZE;
			y_pos = row * BLOCK_SIZE;
			if (map[row][col] == 1)
				draw_filled_square(img, x_pos, y_pos, BLOCK_SIZE, white);
			else
				draw_filled_square(img, x_pos, y_pos, BLOCK_SIZE, black);
			col++;
		}
		row++;
	}
}

void	start_player(t_vars *vars)
{
	vars->player.coord.x = 9 * BLOCK_SIZE;
	vars->player.coord.y = 5 * BLOCK_SIZE;
	vars->player.size = 10;
	vars->player.turnDirection = 0;
	vars->player.walkDirection = 0;
	vars->player.rotationAngle = (PI/2);
	vars->player.walkSpeed = 1;
	vars->player.turnSpeed = 2 * (PI/180);
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
	if (keycode == RIGHT)
		vars->player.turnDirection = 1;
	if (keycode == LEFT)
		vars->player.turnDirection = -1;

	vars->update =  1;
	return (0);
}

int keyRelease(int keycode, t_vars *vars)
{
    if (keycode == UP)
		vars->player.walkDirection = 0;
	if (keycode == DOWN)
		vars->player.walkDirection = 0;
	if (keycode == RIGHT)
		vars->player.turnDirection = 0;
	if (keycode == LEFT)
		vars->player.turnDirection = 0;
	vars->update =  1;
	return (0);
}

int renderPlayer(t_vars *vars)
{
	int playerX;
	int playerY;
	int red;

	red = create_trgb(0, 255, 0, 0);
	playerX = vars->player.coord.x;
	playerY = vars->player.coord.y;
	draw_filled_square(&vars->img, playerX, playerY,
	vars->player.size, red);
	draw_line(&vars->img,
					playerX ,
					playerY ,
					playerX + cos(vars->player.rotationAngle) * 50,
					playerY + sin(vars->player.rotationAngle) * 50,
					red);
	draw_line(&vars->img,
					playerX + 1,
					playerY + 1,
					playerX + 1 + cos(vars->player.rotationAngle) * 50,
					playerY + 1 + sin(vars->player.rotationAngle) * 50,
					red);
	return(0);
}

int movePlayer(t_vars *vars)
{
	float step;
	float nx;
	float ny;

	vars->player.rotationAngle += vars->player.turnDirection * vars->player.turnSpeed;
	step = vars->player.walkDirection * vars->player.walkSpeed;
	nx = vars->player.coord.x + cos(vars->player.rotationAngle) * step;
	ny = vars->player.coord.y + sin(vars->player.rotationAngle) * step;
	
	vars->player.coord.x = nx;
	vars->player.coord.y = ny;

	return(0);
}

int	print_map(t_vars *vars)
{
	int map[N_ROWS][N_COLS] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,2,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1},
		{1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,0,1,0,0,0,1,1,1,1,1},
		{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1},
		{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1,0,0,0,1,1,1,1,1},
		{1,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,1,1,1},
		{1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0,1,0,0,0,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	draw_map(&vars->img, N_ROWS, N_COLS, map);
	renderPlayer(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);

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
	}
	print_map(vars);
	return (0);
}

int		main_1(void)
{

	t_vars	vars;

	start_player(&vars);
	vars.update = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, S_WIDTH, S_HEIGHT, "Hello Word");
	mlx_do_key_autorepeatoff(vars.mlx);
	vars.img.img = mlx_new_image(vars.mlx, S_WIDTH, S_HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);

	mlx_hook(vars.win, 2, 1L << 0, keyPress, &vars);
	mlx_hook(vars.win, 3, 1L << 1, keyRelease, &vars);
	mlx_hook(vars.win, 33, 1L << 17, close_screen, &vars);
	mlx_loop_hook(vars.mlx, game, &vars);
	mlx_loop(vars.mlx);
}