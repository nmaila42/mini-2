#include "minishell.h"

char *ft_readline()
{
    char *line = NULL;
    ssize_t size = 0;
    //getnextline
    get_next_line(size, &line);
    return line;
}

void ft_loop()
{
    char *line;
    char **as;
    int status = 1;

    while(status)
    {
        ft_putstr("msl>");
        line = ft_readline();
        as = ft_split(line);
        status = ft_execute(as);
    }

    free(line);
    free(as);
}

int main(int argc, char **argv)
{
  // Load config files, if any.
  (void)argc;
  (void)argv;
  // Run command loop.
    ft_loop();
  // Perform any shutdown/cleanup.
  return 0;
}