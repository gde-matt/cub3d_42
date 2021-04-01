#include "../includes/get_next_line.h"
#include "../includes/cub3d.h" 

int arg_screen(char **info, t_inputs *inputs)
{
    inputs->r_width = ft_atoi(info[1]);
    inputs->r_height = ft_atoi(info[2]);
    inputs->arg_count++;

    return (0);
}

int check_arg(char **info, t_inputs *inputs)
{
    if  (!ft_strncmp(info[0], "R", 2))
    {
        arg_screen(info, inputs);
        printf("deu R | %d | %d\n", inputs->r_width, inputs->r_height);
    }
    if (!ft_strncmp(info[0], "NO", 3))
    {
        inputs->tex_no = ft_strdup(info[1]);
        inputs->arg_count++;
        printf("deu NO | %s\n", inputs->tex_no);
    }
    if (!ft_strncmp(info[0], "SO", 3))
    {
        inputs->tex_so = ft_strdup(info[1]);
        inputs->arg_count++;
        printf("deu SO | %s\n", inputs->tex_so);
    }
    if (!ft_strncmp(info[0], "WE", 3))
    {
        inputs->tex_we = ft_strdup(info[1]);
        inputs->arg_count++;
        printf("deu WE | %s\n", inputs->tex_we);
    }
    if (!ft_strncmp(info[0], "EA", 3))
    {
        inputs->tex_ea = ft_strdup(info[1]);
        inputs->arg_count++;
        printf("deu EA | %s\n", inputs->tex_ea);
    }
    if (!ft_strncmp(info[0], "S", 2))
    {
        inputs->sprite = ft_strdup(info[1]);
        inputs->arg_count++;
        printf("deu S | %s\n", inputs->sprite);
    }
    if (!ft_strncmp(info[0], "F", 2))
    {
        printf("deu F\n");
        //TODO: funcao para jogar dados no struct F
    }
    if (!ft_strncmp(info[0], "C", 2))
    {
        printf("deu C\n");
        //TODO: funcao para jogar dados no struct C
    }
    return (0);
}

int verify_line(char **line, t_inputs *inputs)
{
    char    **info;

    info = ft_split(*line, ' ');
    if (info[0] != NULL)
    {
        check_arg(info, inputs);
    }
    //TODO: pegar o primeiro argumento do split e verificar o que é
    //TODO: uma vez verificado, pegar as demais informacoes e passar pro struct
    //TODO: se conseguir passar para o struct, aumentar o arg_count
    return (0);
}

int process_input(char *file, t_inputs *inputs)
{
    int     fd;
    int     gnl;
    char    *line;

    fd = open(file, O_RDONLY);
    while ((gnl = get_next_line(fd, &line)) > 0 && inputs->arg_count < 8)
    {
        verify_line(&line, inputs);
    }
    printf("count: %d\n", inputs->arg_count);
    close(fd);
    return (0);
}