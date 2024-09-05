#include <bits/stdc++.h>
using namespace std;

int N, x, y, d, g, ret;
vector<int> a[4][11];
bool maps[101][101];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

void MakeInfo()
{
	for (int i = 0; i < 4; i++)
	{
		// 각 시작 방향마다 앞으로 향할 방향 저장 
		a[i][0].push_back(i);
		a[i][1].push_back((i + 1) % 4);
		for (int j = 2; j <= 10; j++)
		{
			int s = a[i][j - 1].size();
			for (int k = s - 1; k >= 0; k--)
				a[i][j].push_back((a[i][j - 1][k] + 1) % 4);
			for (int k = 0; k < s; k++)
				a[i][j].push_back(a[i][j - 1][k]);
		}
	}
}

void MakeDragonCurve(int x, int y, int d, int g)
{
	maps[y][x] = true;
	for (int i = 0; i <= g; i++)
	{
		for (int j : a[d][i])
		{
			y += dy[j];
			x += dx[j];
			maps[y][x] = true;
		}
	}
}

int main()
{
	MakeInfo();
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> d >> g;
		MakeDragonCurve(x, y, d, g);
	}
	
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (maps[i][j] && maps[i + 1][j] && maps[i + 1][j + 1] && maps[i][j + 1])
				ret++;
	
	cout << ret;
}