#include "cdfile_myHeader.h"
/**
 * myfun_free_env - Free Enviroment Variable Array
 * @env:  Environment variables.
 * Return: Void
 */
void myfun_free_env(char **env)
{
int i;
for (i = 0; env[i]; i++)
{
free(env[i]);
}
}
/**
 * myfun_history - Fill File By User Input
 * @input: User Input
 * Return: -1 Fail 0 Succes
 */
int myfun_history(char *input)
{
char *filename = ".simple_shell_history";
ssize_t fd, w;
int len = 0;
if (!filename)
return (-1);
fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
if (fd < 0)
return (-1);
if (input)
{
while (input[len])
len++;
w = write(fd, input, len);
if (w < 0)
return (-1);
}
return (1);
}
