/* Function to find the length of a given string */
int my_strlen (char str[])
{
	int count;
	
	for (count = 0; str [count] != '\0'; count ++)
		;
	return count;
}