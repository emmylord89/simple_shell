#include "cdfile_myHeader.h"
/**
 * myfun_exit_bul - Exit Statue Shell
 * @cmd: Parsed Command
 * @input: User Input
 * @argv:Program Name
 * @c:Excute Count
 * Return: Void (Exit Statue)
 */
void  myfun_exit_bul(char **cmd, char *input, char **argv, int c)
{
int statue, i = 0;
if (cmd[1] == NULL)
{
free(input);
free(cmd);
exit(EXIT_SUCCESS);
}
while (cmd[1][i])
{
if (_isalpha(cmd[1][i++]) != 0)
{
myfun_prerror(argv, c, cmd);
break;
}
else
{
statue = myfun_atoi(cmd[1]);
free(input);
free(cmd);
exit(statue);
}
}
}
/**
 * myfun_change_dir - Change Dirctorie
 * @cmd: Parsed Command
 * @er: Statue Last Command Excuted
 * Return: 0 Succes 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */
int myfun_change_dir(char **cmd, __attribute__((unused))int er)
{
int value = -1;
char cwd[PATH_MAX];
if (cmd[1] == NULL)
value = chdir(getenv("HOME"));
else if (_strcmp(cmd[1], "-") == 0)
{
value = chdir(getenv("OLDPWD"));
}
else
value = chdir(cmd[1]);
if (value == -1)
{
perror("hsh");
return (-1);
}
else if (value != -1)
{
getcwd(cwd, sizeof(cwd));
setenv("OLDPWD", getenv("PWD"), 1);
setenv("PWD", cwd, 1);
}
return (0);
}
/**
 * myfun_echo_bul - Excute Echo Cases
 * @st:Statue Of Last Command Excuted
 * @cmd: Parsed Command
 * Return: Always 0 Or Excute Normal Echo
 */
int myfun_echo_bul(char **cmd, int st)
{
char *path;
unsigned int  pid = getppid();
if (_strncmp(cmd[1], "$?", 2) == 0)
{
myfun_print_number_in(st);
OUTPUTPRINTER("\n");
}
else if (_strncmp(cmd[1], "$$", 2) == 0)
{
myfun_print_number(pid);
OUTPUTPRINTER("\n");
}
else if (_strncmp(cmd[1], "$PATH", 5) == 0)
{
path = _getenv("PATH");
OUTPUTPRINTER(path);
OUTPUTPRINTER("\n");
free(path);
}
else
return (myfun_print_echo(cmd));
return (1);
}
/**
 * myfun_dis_env - Display Enviroment Variable
 * @cmd:Parsed Command
 * @er:Statue of Last command Excuted
 * Return:Always 0
 */
int myfun_dis_env(__attribute__((unused))
char **cmd, __attribute__((unused)) int er)
{
size_t i;
int len;
for (i = 0; environ[i] != NULL; i++)
{
len = _strlen(environ[i]);
write(1, environ[i], len);
write(STDOUT_FILENO, "\n", 1);
}
return (0);
}
/**
 * myfun_display_help - Displaying Help For Builtin
 * @cmd:Parsed Command
 * @er: Statue Of Last Command Excuted
 * Return: 0 Succes -1 Fail
 */
int myfun_display_help(char **cmd, __attribute__((unused))int er)
{
int fd, fw, rd = 1;
char c;
fd = open(cmd[1], O_RDONLY);
if (fd < 0)
{
perror("Error");
return (0);
}
while (rd > 0)
{
rd = read(fd, &c, 1);
fw = write(STDOUT_FILENO, &c, rd);
if (fw < 0)
{
return (-1);
}
}
my_Write('\n');
return (0);
}
