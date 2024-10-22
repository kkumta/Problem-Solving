#include <bits/stdc++.h>
using namespace std;

const long long INF = 10987654321;
int N;
pair<int, int> matrix[500];
long long dp[500][500];

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> matrix[i].first >> matrix[i].second;
		
	fill(&dp[0][0], &dp[0][0] + 500 * 500, INF);
	
	for (int i = 0; i < N; i++)
		dp[i][i] = 0;
	
	for (int i = 1; i < N; i++) // 몇 개씩 묶을 것인지 
	{
		for (int j = 0; j < N - i; j++) // 시작 
		{
			for (int k = j; k < j + i; k++) // 끝 
				dp[j][j + i] = min(dp[j][k] + dp[k + 1][j + i] + matrix[j].first * matrix[k].second * matrix[j + i].second, dp[j][j + i]); 
		}
	}
	
	cout << dp[0][N - 1];
}