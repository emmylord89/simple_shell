#include "cdfile_myHeader.h"
/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Exit Value By Status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
char *input, **cmd;
int counter = 0, statue = 1, st = 0;
if (argv[1] != NULL)
myfun_read_file(argv[1], argv);
signal(SIGINT, myfun_signal_to_handel);
while (statue)
{
counter++;
if (isatty(STDIN_FILENO))
myfun_prompt();
input = _getline();
if (input[0] == '\0')
{
continue;
}
myfun_history(input);
cmd = myfun_parse_cmd(input);
if (_strcmp(cmd[0], "exit") == 0)
{
myfun_exit_bul(cmd, input, argv, counter);
}
else if (myfun_check_builtin(cmd) == 0)
{
st = myfun_handle_builtin(cmd, st);
myfun_free_all(cmd, input);
continue;
}
else
{
st = myfun_check_cmd(cmd, input, counter, argv);
}
myfun_free_all(cmd, input);
}
return (statue);
}
/**
 * myfun_check_builtin - check builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int myfun_check_builtin(char **cmd)
{
my_bul_t fun[] = {
{"cd", NULL},
{"help", NULL},
{"echo", NULL},
{"history", NULL},
{NULL, NULL}
};
int i = 0;
if (*cmd == NULL)
{
return (-1);
}
while ((fun + i)->command)
{
if (_strcmp(cmd[0], (fun + i)->command) == 0)
return (0);
i++;
}
return (-1);
}
/**
 * myfun_creat_envi - Creat Array of Enviroment Variable
 * @envi: Array of Enviroment Variable
 * Return: Void
 */
void myfun_creat_envi(char **envi)
{
int i;
for (i = 0; environ[i]; i++)
envi[i] = _strdup(environ[i]);
envi[i] = NULL;
}
