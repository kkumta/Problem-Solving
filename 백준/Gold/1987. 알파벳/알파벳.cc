#include <bits/stdc++.h>
using namespace std;

int R, C, ret;
char maps[20][20];
bool visited[20][20], isUsed[26];
int dy[]{0, 1, 0, -1};
int dx[]{1, 0, -1, 0};

void dfs(int y, int x, int depth)
{
	ret = max(depth, ret);
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
		if (visited[ny][nx] || isUsed[maps[ny][nx] - 'A']) continue;
		visited[ny][nx] = true;
		isUsed[maps[ny][nx] - 'A'] = true;
		dfs(ny, nx, depth + 1);
		visited[ny][nx] = false;
		isUsed[maps[ny][nx] - 'A'] = false;
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < C; j++)
			maps[i][j] = tmp[j];
	}
	
	visited[0][0] = true;
	isUsed[maps[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	
	cout << ret;
}