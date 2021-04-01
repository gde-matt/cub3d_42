#include "../includes/get_next_line.h"
#include "../includes/cub3d.h" 

int check_arg(char **info, t_inputs inputs)
{
    if  (!ft_strncmp(info[0], "R", 2))
    {
        printf("deu R\n");
        //TODO: funcao para jogar dados no struct R
    }
    if (!ft_strncmp(info[0], "NO", 3))
    {
        printf("deu NO\n");
        //TODO: funcao para jogar dados no struct NO
    }
    if (!ft_strncmp(info[0], "SO", 3))
    {
        printf("deu SO\n");
        //TODO: funcao para jogar dados no struct SO
    }
    if (!ft_strncmp(info[0], "WE", 3))
    {
        printf("deu WE\n");
        //TODO: funcao para jogar dados no struct WE
    }
    if (!ft_strncmp(info[0], "EA", 3))
    {
        printf("deu EA\n");
        //TODO: funcao para jogar dados no struct EA
    }
    if (!ft_strncmp(info[0], "S", 2))
    {
        printf("deu S\n");
        //TODO: funcao para jogar dados no struct S
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

int verify_line(char **line, t_inputs inputs)
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

int process_input(char *file, t_inputs inputs)
{
    int     fd;
    int     gnl;
    char    *line;

    fd = open(file, O_RDONLY);
    while ((gnl = get_next_line(fd, &line)) > 0 && inputs.arg_count < 8)
    {
        verify_line(&line, inputs);
    }
    close(fd);
    return (0);
}