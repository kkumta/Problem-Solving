#include <bits/stdc++.h>
using namespace std;

int N, ret;
int a[20][20], na[20][20];
int b[5];

void calc()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			na[i][j] = a[i][j];
	
	for (int i = 0; i < 5; i++)
	{
		if (b[i] == 0) // 오른쪽으로 
		{
			for (int r = 0; r < N; r++)
			{
				for (int c = N - 1; c >= 0; c--)
				{
					if (na[r][c] == 0) continue;
					// 왼쪽에 있는 수랑 합치기 
					for (int j = c - 1; j >= 0; j--)
					{
						if (na[r][j] == na[r][c])
						{
							na[r][c] *= 2;
							na[r][j] = 0;
							break;
						}
						else if (na[r][j] != 0)
							break;
					}
					// 오른쪽이 비면 이동시키기 
					for (int j = c + 1; j < N; j++)
					{
						if (na[r][j] != 0) break;
						if (na[r][j] == 0)
						{
							na[r][j] = na[r][j - 1];
							na[r][j - 1] = 0;
						}
					}
				}
			}
		}
		else if (b[i] == 1) // 왼쪽으로 
		{
			for (int r = 0; r < N; r++)
			{
				for (int c = 0; c < N; c++)
				{
					if (na[r][c] == 0) continue;
					// 오른쪽에 있는 수랑 합치기 
					for (int j = c + 1; j < N; j++)
					{
						if (na[r][j] == na[r][c])
						{
							na[r][c] *= 2;
							na[r][j] = 0;
							break;
						}
						else if (na[r][j] != 0)
							break;
					}
					// 왼쪽이 비면 이동시키기 
					for (int j = c - 1; j >= 0; j--)
					{
						if (na[r][j] != 0) break;
						if (na[r][j] == 0)
						{
							na[r][j] = na[r][j + 1];
							na[r][j + 1] = 0;
						}
					}
				}
			}			
		}
		else if (b[i] == 2) // 위쪽으로 
		{
			for (int c = 0; c < N; c++)
			{
				for (int r = 0; r < N; r++)
				{
					if (na[r][c] == 0) continue;
					// 아래쪽에 있는 수랑 합치기 
					for (int j = r + 1; j < N; j++)
					{
						if (na[j][c] == na[r][c])
						{
							na[r][c] *= 2;
							na[j][c] = 0;
							break;
						}
						else if (na[j][c] != 0)
							break;
					}
					// 위쪽이 비면 이동시키기 
					for (int j = r - 1; j >= 0; j--)
					{
						if (na[j][c] != 0) break;
						if (na[j][c] == 0)
						{
							na[j][c] = na[j + 1][c];
							na[j + 1][c] = 0;
						}
					}
				}
			}			
		}
		else if (b[i] == 3) // 아래쪽으로 
		{
			for (int c = 0; c < N; c++)
			{
				for (int r = N - 1; r >= 0; r--)
				{
					if (na[r][c] == 0) continue;
					// 위쪽에 있는 수랑 합치기 
					for (int j = r - 1; j >= 0; j--)
					{
						if (na[j][c] == na[r][c])
						{
							na[r][c] *= 2;
							na[j][c] = 0;
							break;
						}
						else if (na[j][c] != 0)
							break;
					}
					// 아래쪽이 비면 이동시키기 
					for (int j = r + 1; j < N; j++)
					{
						if (na[j][c] != 0) break;
						if (na[j][c] == 0)
						{
							na[j][c] = na[j - 1][c];
							na[j - 1][c] = 0;
						}
					}
				}
			}				
		}
	}
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ret = max(na[i][j], ret);
}

void go(int k)
{
	if (k == 5)
	{
		calc(); 
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		b[k] = i;
		go(k + 1);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];
	
	go(0);
	
	cout << ret;
}