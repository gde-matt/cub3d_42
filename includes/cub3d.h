#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <math.h>

typedef struct  s_data 
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef	struct	s_vars
{
	void *mlx;
	void *win;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_horizontal_line(t_data *data, int x, int y, int size, int color);
void    draw_vertical_line(t_data *data, int x, int y, int size, int color);
void	draw_filled_rectangle(t_data *data, int x, int y, int width, int height, int color);
void	draw_empty_rectangle(t_data *data, int x, int y, int width, int height, int color);
void	draw_empty_circle(t_data *data, int x, int y, int radius, int color);
int		create_trgb(int t, int r, int g, int b);
void	draw_map(t_data *data, int n_rows, int n_cols, int map[n_rows][n_cols], int block_size);
int     main(void);
int		close(int keycode, t_vars *vars);

#endif