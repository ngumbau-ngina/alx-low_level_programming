#include <stdlib.h>
#include <stdio.h>
/**
 * malloc_checked - allocates memory using malloc
 * @b: size to be allocated
 * Return: pointer to allocated memory or exit with 98
 **/
void *malloc_checked(unsigned int b)
{
	void *ptr;
		
	ptr = malloc(b);
	if (ptr == NULL)
		exit(98);

	return (ptr);
}
