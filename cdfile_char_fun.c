#include "cdfile_myHeader.h"
/**
 * _strlen - lenght of string
 * @s:char
 * Return:int
 */
int _strlen(char *s)
{
int i;
for (i = 0; s[i] != '\0'; i++)
{
continue;
}
return (i);
}
/**
 * my_Write - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int my_Write(char c)
{
return (write(1, &c, 1));
}
/**
 * _strncpy - copie a string
 * @dest:char
 *  @src:char
 * @n:int
 * Return:char
 */
char *_strncpy(char *dest, char *src, int n)
{
int i;
i = 0;
while (i < n && *(src + i))
{
*(dest + i) = *(src + i);
i++;
}
while (i < n)
{
*(dest + i) = '\0';
i++;
}
return (dest);
}
/**
 * myfun_atoi - convert to a int
 * @s:string
 * Return:int
 */
int myfun_atoi(char *s)
{
int i, j, n, x;
i = n = 0;
x = 1;
while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
{
if (s[i] == '-')
x *= -1;
i++;
}
j = i;
while ((s[j] >= '0') && (s[j] <= '9'))
{
n = (n * 10) + x * ((s[j]) - '0');
j++;
}
return (n);
}
/**
 * _puts - print a string
 * @str:pointer char
 * return:void
 */
void _puts(char *str)
{
int i;
for (i = 0; str[i] != '\0'; i++)
{
my_Write(str[i]);
}
my_Write('\n');
return;
}
