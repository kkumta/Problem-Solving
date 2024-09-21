#include <bits/stdc++.h>
using namespace std;

int N, M;
int maps[50][50], d[50][50];
bool visited[50][50];
int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};

int dfs(int y, int x)
{
	if (y >= N || y < 0 || x >= M || x < 0) return 0;
	if (maps[y][x] == 0) return 0;
	// 순환할 때 
	if (visited[y][x])
	{
		cout << -1;
		exit(0);
	}
	
	// 이미 탐색한 적 있을 때 (DP)
	if (d[y][x]) return d[y][x];

	visited[y][x] = true;
	int ret = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i] * maps[y][x];
		int nx = x + dx[i] * maps[y][x];

		ret = max(ret, dfs(ny, nx) + 1);
	}
	
	visited[y][x] = false;
	d[y][x] = ret;
	
	return ret;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++)
		{
			if (tmp[j] == 'H') maps[i][j] = 0;
			else maps[i][j] = tmp[j] - '0';
		}
	}

	cout << dfs(0, 0);	
}