#include "monty.h"


#define MAX_LINE_LENGTH 1024
/**
 *getline - read a line from file
 *
 *@str: string pointer
 *@length: lenght of chars to read
 *@stream: file or stdin
 *
 *Return: number of char read
*/

ssize_t getline(char **str, size_t *length, FILE *stream)
{
	int line_length, c;
	char *line = *str;

	if (fgets(line, length, stream))
	{
		/* If fgets() reads a line successfully,*/
		/* check if the line is too long and needs to be truncated.*/
		line_length = strlen(line);
		if (line_length > 0 && line[line_length - 1] != '\n')
		{
/* If the line is too long, truncate it and discard the rest of the input.*/
			line[line_length - 1] = '\0';
			while ((c = getchar()) != '\n' && c != EOF);
		}
		return ((ssize_t) strlen(line));
	} else {
		/* If fgets() fails to read a line, return NULL.*/
		return NULL;
	}
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
		return 0;

	for (count = 0; c != '\n' && count < size - 1; count++)
	{
		c = getc(stream);

		if (c == EOF) {
			if (count == 0)
				return (-1);
			break;
		}

		buf[count] = (char) c;
	}

	buf[count] = '\0';
	return ((ssize_t) count);
}
