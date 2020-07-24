#include "minishell.h"

void ft_loop()
{
    char *line;
    char **as;
    int status = 1;

    while(status)
    {
        ft_putstr("shell=>>>");
        line = ft_readline();
        as = ft_split(line);
        status = ft_execute(as);
    }

    free(line);
    free(as);
}

int ft_execute(char **args)
{
  int nocmd = 4, i, swithchargs = 0;
  char *listcmd[nocmd];
  char *username;

  listcmd[0] = "exit";
  listcmd[1] = "cd";
  listcmd[2] = "setenv";
  listcmd[3] = "unsetenv";

  for(i = 0; i < nocmd; i++)
  {
    if(ft_strcmp(args[0], listcmd[i]) == 0)
    {
      swithchargs = i + 1;
      break ;
    }
  }
  switch(swithchargs){
    case 1:
      ft_putstr("\nexited form the shell\n");
      exit (0);

    case 2:
      chdir(args[1]);
      return 1;

    case 3:
      setenv(args[1], args[2], i);
      return (1);
    
    case 4:
      unsetenv(args[1]);
      return 1;

    default :
      break ;

  }

  //return 0;
   return ft_launch(args);

}

int ft_launch(char **args)
{
  pid_t pid; 
  pid_t wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      ft_putstr(args[0]);
       ft_putstr(" : command not found\n");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    ft_putstr("Error");
  } else {
      while(!wait(&status))
      {
        wpid = waitpid(pid, &status, WUNTRACED);
      }
  }

  return 1;
}

char	**ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char **ret;

	if (!(ret = (char **)malloc(sizeof(char *) * (2048))))
		return(NULL);
	while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;	
	while(str[i])
	{
		j = 0;
		if(!(ret[k] = (char *)malloc(sizeof(char)*(4096))))
			return(NULL);
		while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			ret[k][j++] = str[i++];
		while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		ret[k][j] = '\0';
		k++;
	}
	ret[k] = NULL;
	return(ret);
}

char *ft_readline()
{
    char *line = NULL;
    ssize_t size = 0;
    //getnextline
    get_next_line(size, &line);
    return line;
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
