#include <bits/stdc++.h>
using namespace std;

int R, C, K, ret;
char maps[5][5];
bool visited[5][5];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void dfs(int y, int x, int d)
{
	if (y == 0 && x == C - 1)
	{
		if (d == K)
			ret++;
			
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		
		if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) continue;
		if (maps[nextY][nextX] == 'T') continue;
		if (visited[nextY][nextX]) continue;
		
		visited[nextY][nextX] = true;		
		dfs(nextY, nextX, d + 1);		
		visited[nextY][nextX] = false;
	}
}

int main()
{
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> maps[i][j];
	
	visited[R -1][0] = true;		
	dfs(R - 1, 0, 1);
	
	cout << ret;
}