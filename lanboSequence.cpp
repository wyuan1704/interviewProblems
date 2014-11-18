#include <iostream>
#include <vector>
using namespace std;
/*
Oct 17, 2014, Amazon
For a positive integer N, every INT in [1~N] appears twice in a vector, whose size is 2N, such that there are exactly INT integers between the two INTs.
Eg. for N = 3, one possible sequence is "3, 1, 2, 1, 3, 2".
The interviewer tells me that this sequence is like Lanbo's sequence. But I don't find it in google or baidu. What is its real name?
Question:
	Given N, find all lanbo sequence if there is.
*/
// I find that for N in [1~299], there's only one lanbo sequence for N==3. 
void dfs(vector<vector<int> > &res, vector<int> &seq, const int &N, int k)
{
	if(k == 0)
	{
		res.push_back(seq);
		return;
	}
	int end = 2*N-k-1;
	for(int i=0; i< end ; i++)
	{
		if(seq[i] == 0 && seq[i+k+1] == 0)
		{
			seq[i] = k;
			seq[i+k+1] = k;
			dfs(res, seq, N, k-1);
			// restore
			seq[i] == 0;
			seq[i+k] == 0;
		}
	}
}
int main()
{
	for(int N = 1; N < 300; N++)
	{
		vector<vector<int> > res;
		vector<int> seq(N*2, 0);
		dfs(res, seq, N, N);
		if(!res.empty())
		{
			cout << N << endl;
		}
	}
	return 0;
}