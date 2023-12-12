#include "cdfile_myHeader.h"
/**
 * myfun_parse_cmd - Parse Line Of Input
 * @input:User Input To Parse
 * Return: Array Of Char (Parsed):Simple Shell
 */
char **myfun_parse_cmd(char *input)
{
char **tokens;
char *token;
int i, buffsize = MY_BUFSIZE;
if (input == NULL)
return (NULL);
tokens = malloc(sizeof(char *) * buffsize);
if (!tokens)
{
perror("hsh");
return (NULL);
}
token = _strtok(input, "\n ");
for (i = 0; token; i++)
{
tokens[i] = token;
token = _strtok(NULL, "\n ");
}
tokens[i] = NULL;
return (tokens);
}
