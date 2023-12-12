#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <errno.h>

/**###### environ var ######*/

extern char **environ;

/**##### My_MACROS ######*/

#define MY_BUFSIZE 1024
#define MY_DELIM " \t\r\n\a"
#define OUTPUTPRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))


/** ###### cdfile_builtin.c fun ###*/
int myfun_dis_env(char **cmd, int er);
int myfun_display_help(char **cmd, int er);
int myfun_echo_bul(char **cmd, int er);
int myfun_change_dir(char **cmd, int er);
void myfun_exit_bul(char **cmd, char *input, char **argv, int c);

/** ###### cdfile_char_fun.c fun ###*/
int my_Write(char c);
int _strlen(char *s);
void _puts(char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
int myfun_atoi(char *s);
char *_strncpy(char *dest, char *src, int n);

/** ###### cdfile_execute_file.c fun ###*/
void myfun_read_file(char *filename, char **argv);
void myfun_treat_file(char *line, int counter, FILE *fd, char **argv);
void myfun_exit_bul_for_file(char **cmd, char *line, FILE *fd);

/** ###### cdfile_execute.c fun ###*/
int myfun_handle_builtin(char **cmd, int er);
int myfun_check_cmd(char **tokens, char *line, int count, char **argv);
void myfun_signal_to_handel(int sig);

/** ###### cdfile_finding_path.c fun ###*/
int myfun_path_cmd(char **line);
char *myfun_build(char *token, char *value);
char *_getenv(char *name);

/** ###### cdfile_get_line.c fun ###*/
char *_getline(void);
void myfun_hashtag_handle(char *buff);

/** ###### cdfile_history.c fun ###*/
int myfun_history(char *input);
void myfun_free_env(char **env);

/** ###### cdfile_memory_management.c fun ###*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void myfun_free_all(char **input, char *line);
void *myfun_fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);

/** ###### cdfile_more_bul.c fun ###*/
int myfun_history_dis(char **cmd, int er);
int myfun_print_echo(char **cmd);

/** ###### cdfile_more_charfun.c fun ###*/
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void myfun_array_rev(char *arr, int len);
int myfun_intlen(int num);
char *_itoa(unsigned int n);

/** ###### cdfile_more_fun.c ###*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strchr(char *s, char c);

/** ###### cdfile_output.c fun ###*/
void myfun_prerror(char **argv, int c, char **cmd);

/** ###### cdfile_parsing.c fun ###*/
char **myfun_parse_cmd(char *cmd);

/** ###### cdfile_printing.c fun ###*/
void myfun_print_number(unsigned int n);
void myfun_print_number_in(int n);

/** ###### cdfile_promptetfun.c fun ###*/
void myfun_prompt(void);
void myfun_print_error(char *line, int c, char **argv);

/** ###### cdfile_shell.c fun ###*/
int myfun_check_builtin(char **cmd);
void myfun_creat_envi(char **envi);

/** ###### cdfile_strtok.c fun ###*/
unsigned int myfun_check_delim(char c, const char *str);
char *_strtok(char *str, const char *tok);


/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} my_bul_t;

#endif

