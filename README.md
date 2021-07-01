42 project, recoding our own little bash. A program capable of parsing a prompt and launching executables with arguments, along with a few built-in functions.

![alt text](https://camo.githubusercontent.com/d4cc67298f77eb7faafa6a6ae7cf24335f9bad2a11af96de4400d9ef3e29323c/68747470733a2f2f692e696d6775722e636f6d2f456e31334137702e706e67)

Minishell runs executables from an absolute, relative or environment PATH (/bin/ls or ls), including arguments or options. ' and " work the same as bash, except for multiline commands.

You can separate commands with ;, as well as use redirections > >> < and pipes |.

Environment variables are handled, like $HOME, including the return code $?.

Finally, you can use Ctrl-C to interrupt and Ctrl-\ to quit a program, as well as Ctrl-D to throw an EOF, same as in bash.

A few of the functions are "built-in", meaning we don't call the executable, we re-coded them directly. It's the case for echo, pwd, cd, env, export, unset and exit.
