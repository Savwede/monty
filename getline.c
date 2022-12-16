#include "monty.h"


#define BUFFER_SIZE 1024
/**
 *getline - read a line from file
 *
 *@lineptr: string pointer
 *@n: lenght of chars to read
 *@stream: file or stdin
 *
 *Return: number of char read
*/


ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	int c, i = 0;

	/* Allocate a buffer if one is not provided*/
	if (*lineptr == NULL)
	{
		*lineptr = malloc(BUFFER_SIZE);
		if (*lineptr == NULL)
			return (-1);
		*n = BUFFER_SIZE;
	}
	while ((c = fgetc(stream)) != EOF)
	{
		/*Check if the buffer is full*/
		if ((size_t) i == *n)
		{
			/*Increase the size of the buffer*/
			*lineptr = realloc(*lineptr, *n * 2);
			if (*lineptr == NULL)
				return (-1);

			*n *= 2;
		}
		(*lineptr)[i++] = c;

		if (c == '\n')
			break;
	}

	/* Add a null terminator to the end of the string*/
	(*lineptr)[i] = '\0';

	return ((ssize_t) i);
}


/**
 * getline_1 - reads a line from a file
 *
 *@buf: the string pointer
 *@size: size of char to read
 *@stream: file or stdin
 *
 *Return: size of char red
 */

ssize_t getline_1(char *buf, size_t size, FILE *stream)
{
	size_t count;
	int c = 0;

	if (size == 0)
		return (0);

	for (count = 0; c != '\n' && count < size - 1; count++)
	{
		c = getc(stream);

		if (c == EOF)
		{
			if (count == 0)
				return (-1);
			break;
		}

		buf[count] = (char) c;
	}

	buf[count] = '\0';
	return ((ssize_t) count);
}
