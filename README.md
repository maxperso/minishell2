# MINISHELL2
**`Epitech 1st year project`**

## Project description

Minishell2 is the second project of the Shell Programming branch at EPITECH.
It's a minimum viable version of a real shell.
The main goal is to have a good understanding of process creation and
synchronisation using the C programmming language.

## How to use ?

### Compile
input
```bash
make
```
### Run
input
```bash
./mysh
```

## Main Project Instructions

### Mandatory

- Can only use C
- Must respect the school imposed coding style
- No memory leaks
- Implement a series of builtins: `echo`, `cd`, `setenv`, `unsetenv`, `env`, `exit`
- Manage the errors without using `errno`, by displaying a message adapted
to the error output
- Can only use these standard library functions:
    - malloc, free
    - access
    - open, close, read, write
    - opendir, readdir, closedir
    - getcwd, chdir
    - stat, lstat, fstat
    - fork, execve
    - wait, waitpid, wait3, wait4
    - signal, kill
    - exit
- Must have a Makefile to build the program
- Handle program interruption (Ctrl + D)
- Handle complexes commands with multiples pipes and redirections

## Coverage

- 01 - mandatory minishell1 (64,7%)
- 07 - separator (100%)
- 08 - simple pipe (100%)
- 09 - simple redirections (100%)
- 10 - advanced pipe (85%)
- 11 - advanced redirections (50%)
- 12 - advanced manipulations (50%)
