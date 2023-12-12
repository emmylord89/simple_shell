#include "cdfile_myHeader.h"
/**
 * myfun_print_number_in -Print Number Putchar
 * @n:Integer
 * Return: void
 */
void myfun_print_number_in(int n)
{
unsigned int x = n;
if (n < 0)
{
my_Write('-');
x = -x;
}
if ((x / 10) > 0)
myfun_print_number(x / 10);
my_Write(x % 10 + '0');
}
/**
 * myfun_print_number -Print Unsigned Int Putchar
 * @n: Unisigned Integer
 * Return: Void
 */
void myfun_print_number(unsigned int n)
{
unsigned int x = n;
if ((x / 10) > 0)
myfun_print_number(x / 10);
my_Write(x % 10 + '0');
}
