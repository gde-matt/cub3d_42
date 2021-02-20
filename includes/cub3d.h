#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define BLOCK_SIZE 32
# define N_ROWS     7
# define N_COLS     10
# define S_WIDTH    N_COLS * BLOCK_SIZE
# define S_HEIGHT   N_ROWS * BLOCK_SIZE

# define ESC		65307
# define UP	        65362
# define DOWN		65364
# define RIGHT		65363
# define LEFT		65361

# define PI         3.14

typedef struct  s_img 
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_img;

typedef struct s_coord
{
    float   x;
    float   y;
}   t_coord;

typedef struct s_player
{
    t_coord coord;
    int     size;
    int     turnDirection;
    int     walkDirection;
    float   rotationAngle;
    float   walkSpeed;
    float   turnSpeed;
}   t_player;

typedef	struct	s_vars
{
	void       *mlx;
	void       *win;
    int        update;
    t_player   player;
    t_img      img;

}	t_vars;






void	my_mlx_pixel_put(t_vars *img, int x, int y, int color);
void	draw_horizontal_line(t_vars *img, int x, int y, int size, int color);
void    draw_vertical_line(t_vars *img, int x, int y, int size, int color);
void	draw_filled_rectangle(t_vars *img, int x, int y, int width, int height, int color);
void	draw_empty_rectangle(t_vars *img, int x, int y, int width, int height, int color);
void	draw_empty_circle(t_vars *img, int x, int y, int radius, int color);
int		create_trgb(int t, int r, int g, int b);
void	draw_map(t_img *img, int n_rows, int n_cols, int map[n_rows][n_cols], int block_size);
int     main(void);
int		close(int keycode, t_vars *vars);
void	start_player(t_vars *vars);
int     keyPress(int keycode, t_vars *vars);
int     keyRelease(int keycode, t_vars *vars);
int     renderPlayer(t_vars *vars);
int     movePlayer(t_vars *vars);
int     print_map(t_vars *vars);
int     update(t_vars *vars);
int     game(t_vars *vars);



#endif