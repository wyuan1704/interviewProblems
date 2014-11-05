// wyuan; 11/05/2014; 
1) Given char *strs[count], where count is very large, concatenate them with ','. Make it fast. Assume there are enough space. Eg, {"I", "love", "her"} --> "I,love,her".
// "new" consumes most time. If we call "string +=" many times, it is very slow.

char *strcatWithComma(char *strs[], const int &count)
{
	if(count < 1)
		return NULL;
	size_t totalLen = 0;
	for(int i=0; i<count; i++)
		totalLen += strlen(strs[i]);
	
	char *res = new char(totalLen + (count-1) + 1); // number of ',' + '\0'
	char *cur = res;
	for(int i=0; i<count; i++)
	{
		size_t curLen = strlen(strs[i]);
		memcpy(cur, strs[i], curLen);
		cur += curLen;
		*cur++ = ',';
	}
	*cur = '\0';
	return res;
}

2) Heap related
If we have a parsed file, vector<string> parsedWords, and a dictionary vector<string> cadis. Find the smallest sub-array in parsedWords, which contains all the words in cadis.
We can use a trie or unordered_set to store cadis. Suppose we have got a reverted index table
	China	index1, index2, ...
	USA	indexU1, U2, ...
	...
find a index set, whose difference is the smallest.

3) Given an un-sorted array, find all (or any) sub-arrays, whose sum is closest to a given target T. Find at least a O(NlogN) solution.
http://stackoverflow.com/questions/16388930/how-to-find-the-subarray-that-has-sum-closest-to-zero-or-a-certain-value-t-in-o
