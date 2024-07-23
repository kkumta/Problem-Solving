#include <bits/stdc++.h>
using namespace std;

int N, M, ret;
int maps[4][4];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++)
		{
			maps[i][j] = tmp[j] - '0';
		}
	}

	for (int i = 0; i <= (1 << (N * M + 1) - 1); i++)
	{
		int sum = 0;
		// 가로 합 
		for (int n = 0; n < N; n++)
		{
			int cur = 1;
			for (int m = M - 1; m >= 0; m--)
			{
				// 가로일 경우 
				if (!(i & (1 << (n * M + m))))
				{
					sum += cur * maps[n][m];
					cur *= 10;
				}
				else
					cur = 1;
			}
		}
		// 세로 합 
		for (int m = 0; m < M; m++)
		{
			int cur = 1;
			for (int n = N - 1; n >= 0; n--)
			{
				// 세로일 경우 
				if (i & (1 << (n * M + m)))
				{
					sum += cur * maps[n][m];
					cur *= 10; 
				}
				else
					cur = 1;
			}
		}
		
		ret = max(ret, sum);
	}
	
	cout << ret;
}