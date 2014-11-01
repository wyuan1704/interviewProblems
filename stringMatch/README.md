Qustion: Sensitive Words Searching
Given a string haystack stored in a file haystack.txt, and a set of sensitive words needles, find all the occurences of any needle in haystack.

I'm not sure about the best way to solve this. Let's first check strstr().
http://stackoverflow.com/questions/3183582/what-is-the-fastest-substring-search-algorithm suggests a good source, http://www-igm.univ-mlv.fr/~lecroq/string/index.html, where gives 33 methods of strstr(). The author says that "The Boyer-Moore algorithm is considered as the most efficient string-matching algorithm in usual applications. A simplified version of it (or the entire algorithm) is often implemented in text editors for the "search" and "substitute" commands." To do -- implement all these methods.

https://github.com/RaphaelJ/fast_strstr.git gives a practical implementation, which reads the string by shifting a reading window the size of the sub-string and keeps track of a SUM of all the charactors in the window. The benchmarks shows that it's faster than GUN::strstr(). The author suggests the user to test this on their data before using it.
