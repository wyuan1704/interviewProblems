If we can scan the stream twice and it is an ASCII string, it will be very simple as below:
1)
char firstNonRepeatingChar(const char *str)
{
	if(str == NULL)
		return '\0';
	size_t map[256] = {0};
	const char *cur = str;
	while(*cur != '\0')
		map[*cur++]++;
	cur = str;
	while(*cur != '\0')
	{
		if(map[*cur] == 1)
			return *cur;
		cur++;
	}
	return '\0';
}

But if the string is from a very large file and it is a w_char string, what should we do?	

http://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/

http://stackoverflow.com/questions/24672943/find-first-non-repeating-character-in-a-stream-of-characters

