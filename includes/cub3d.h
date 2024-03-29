#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define BLOCK_SIZE 50
# define N_ROWS     14
# define N_COLS     33
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

typedef struct s_inputs
{
    int r_width;
    int r_height;
    char    *tex_no;
    char    *tex_so;
    char    *tex_we;
    char    *tex_ea;
    char    *sprite;
    int     floor;
    int     ceilling;
    int     arg_count;
}   t_inputs;


void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	draw_line(t_img *data, int start_x, int start_y, int end_x, int end_y, int color);
void	draw_filled_square(t_img *img, int x, int y, int size, int color);
int		create_trgb(int t, int r, int g, int b);
void	draw_map(t_img *img, int n_rows, int n_cols, int map[n_rows][n_cols]);
int     main_1(void);
int     main(int argc, char *argv[]);
int		close_screen(int keycode, t_vars *vars);
void	start_player(t_vars *vars);
int     keyPress(int keycode, t_vars *vars);
int     keyRelease(int keycode, t_vars *vars);
int     renderPlayer(t_vars *vars);
int     movePlayer(t_vars *vars);
int     print_map(t_vars *vars);
int     update(t_vars *vars);
int     game(t_vars *vars);

int     process_input(char *file, t_inputs *inputs);
int     verify_line(char **line, t_inputs *inputs);
int     check_arg(char **info, t_inputs *inputs);
int     arg_screen(char **info, t_inputs *inputs);

char	**ft_split(char const *s, char c);
char	**fill_matrix(char **matrix, char const *s, char c);
char	**fill_cols(char **matrix, char const *s, char c);
int		count_words(char const *s, char c);
int     ft_strncmp(const char *s1, const char *s2, unsigned long int n);
int	    ft_isspace(char c);
int	    ft_atoi(const char *str);


#endif