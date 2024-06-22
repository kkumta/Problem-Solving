#include <bits/stdc++.h>
using namespace std;

int R, C, ret;
char maps[50][50];
int visited[50][50];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = 1;
	while(!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		
		if (visited[curY][curX] > ret)
			ret = visited[curY][curX];
		
		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			
			if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) continue;
			if (maps[nextY][nextX] == 'W') continue;
			if (visited[nextY][nextX] != 0) continue;
			
			q.push(make_pair(nextY, nextX));
			visited[nextY][nextX] = visited[curY][curX] + 1;
		}
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < C; j++)
		{
			maps[i][j] = s[j];
		}
	}
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
			if (maps[i][j] == 'L')
				bfs(i, j);
		}
	}
	
	cout << ret - 1;
}