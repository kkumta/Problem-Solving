#include <bits/stdc++.h>
using namespace std;

int T, K, ret;
int a[1001][8], na[1001][8];

int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < 8; j++)
			a[i][j] = tmp[j] - '0';
	}
	
	cin >> K;
	// 회전
	for (int i = 0; i < K; i++)
	{
		int t, s; // 회전시킨 톱니바퀴 번호, 방향 
		cin >> t >> s;
		
		// a -> na
		for (int j = 1; j <= T; j++)
			for (int k = 0; k < 8; k++)
				na[j][k] = a[j][k];
				
		// 나 자신
		if (s == 1) // 시계 방향으로 회전
		{
			// na에 회전한 것 기록
			for (int j = 0; j < 8; j++)
				na[t][(j + 1) % 8] = a[t][j];
		}
		else // 반시계 방향으로 회전
		{
			// na에 회전한 것 기록
			for (int j = 0; j < 8; j++)
				na[t][(j + 7) % 8] = a[t][j];						
		} 
		
		// 오른쪽 톱니바퀴들
		for (int curT = t, curS = s; curT < T; curT++)
		{
			// 회전 
			if (a[curT][2] != a[curT + 1][6])
			{
				curS *= -1;
				if (curS == 1) // 시계 방향으로 회전
				{
					// na에 회전한 것 기록
					for (int j = 0; j < 8; j++)
						na[curT + 1][(j + 1) % 8] = a[curT + 1][j];
				}
				else // 반시계 방향으로 회전
				{
					// na에 회전한 것 기록
					for (int j = 0; j < 8; j++)
						na[curT + 1][(j + 7) % 8] = a[curT + 1][j];						
				} 
			}
			else
			{
				break;
			}
		}		
		 
		// 왼쪽 톱니바퀴들 
		for (int curT = t, curS = s; curT > 1; curT--)
		{
			// 회전 
			if (a[curT][6] != a[curT - 1][2])
			{
				curS *= -1;
				if (curS == 1) // 시계 방향으로 회전
				{
					// na에 회전한 것 기록
					for (int j = 0; j < 8; j++)
						na[curT - 1][(j + 1) % 8] = a[curT - 1][j];
				}
				else // 반시계 방향으로 회전
				{
					// na에 회전한 것 기록
					for (int j = 0; j < 8; j++)
						na[curT - 1][(j + 7) % 8] = a[curT - 1][j];						
				} 
			}
			else
			{
				break;
			}
		}
		// na -> a
		for (int j = 1; j <= T; j++)
			for (int k = 0; k < 8; k++)
				a[j][k] = na[j][k];	
	}
	
	// 톱니바퀴 개수 구하기
	for (int i = 1; i <= T; i++)
		if (a[i][0] == 1) ret++;		
		
	cout << ret;
}