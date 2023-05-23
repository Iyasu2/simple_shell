/**
 * print - prints a string to stdout
 * @string: string to be printed
 * @stream: stream to print out to
 *
 * Return: void
 */
void print(char *string, int stream)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
	write(stream, &string[i], 1);
}