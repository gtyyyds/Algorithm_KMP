#include<iostream>
#include<string>
using namespace std;
class KMP
{
public:
	KMP(string pat)
	{
		this->pat = pat;
		int M = pat.length();
		this->dp = new int*[M];
		//cout << M << endl;
		for (int i = 0; i < M; i++)
		{
			this->dp[i] = new int[256];
		}
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < 256; j++)
			{
				dp[i][j] = 0;
			}
		}
		dp[0][pat[0] - '0'] = 1;
		int X = 0;
		for (int j = 1; j < M; j++)
		{
			for (int c = 0; c < 256; c++)
			{
				this->dp[j][c] = dp[X][c];
			}
			this->dp[j][pat[j] - '0'] = j + 1;
			X = dp[X][pat[j] - '0'];
		}
	}
	int seach(string txt)
	{
		int M = pat.length();
		int N = txt.length();
		int j = 0;
		for (int i = 0; i < N; i++)
		{
			j=dp[j][txt[i]-'0'];
			if (j == M)
				return i - M + 1;
		}
		return -1;
	}
private:
	int **dp;
	string pat;
};
int main()
{
	KMP kp("cd");
	cout << kp.seach("abcdefg");
}