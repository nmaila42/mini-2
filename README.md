# minishell
The objective of this project is to create the simplest shell script.

# Objectives
Through the Minishell project, you will get to the core of the Unix system and explore an important part of this system’s API:

process creation
synchronisation.
Executing a command inside a shell implies creating a new process, which execution and final state will be monitored by its parent’s process. This set of functions will be the key to success for your Minishell, so be sure to code the cleanest, simplest program possible.

# Specification Of Task
You must program a mini UNIX command interpreter.\
This interpreter must display a prompt (a simple "$> " for example) and wait till you type a command line, validated by pressing enter.\
The prompt is shown again only once the command has been completely executed.\
The command lines are simple, no pipes, no redirections or any other advanced functions.\
The executable are those you can find in the paths indicated in the PATH variable.\
In cases where the executable cannot be found, it has to show an error message and display the prompt again.\
You must manage the errors without using errno, by displaying a message adapted to the error output.\
You must deal correctly with the PATH and the environment (copy of system char **environ).\
