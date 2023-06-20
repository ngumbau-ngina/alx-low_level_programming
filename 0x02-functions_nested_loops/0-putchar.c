#include <stdio.h>

/**
* main - Print the word "_putchar"
*
* Return: Always 0 (Success)
*/
int main(void)
{
	int i[] = "_putchar";

	for (i = 0; i <= 9; i++)
		{
		putchar (i[i]);
		}
	putchar ("\n");
	return (0);
}
