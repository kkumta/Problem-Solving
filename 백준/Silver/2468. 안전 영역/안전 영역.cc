#include <bits/stdc++.h>
using namespace std;

int N;
int maps[100][100];
bool visited[100][100];
int h, ans = 1;

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

void dfs(int y, int x, int h)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (maps[ny][nx] <= h) continue;
		if (visited[ny][nx]) continue;
		
		visited[ny][nx] = true;
		dfs(ny, nx, h);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] > h) h = maps[i][j];
		}
		
	for (int i = 1; i <= h; i++)
	{
		fill(&visited[0][0], &visited[0][0] + 100 * 100, false);
		int cnt = 0;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
			{
				if (maps[j][k] <= i || visited[j][k]) continue;
				dfs(j, k, i);
				cnt++;
			}
		if (cnt > ans) ans = cnt;
	}
	
	cout << ans;
}