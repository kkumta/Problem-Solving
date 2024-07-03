#include <bits/stdc++.h>
using namespace std;

int N, M, ay, ax, by, bx, ret = 1;
char maps[300][300];
bool visited[300][300];
int dy[]{0, 1, 0, -1};
int dx[]{1, 0, -1, 0};

bool bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(ay - 1, ax - 1));
	visited[ay - 1][ax - 1] = true;
	
	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second; q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			
			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
			if (visited[nextY][nextX]) continue;
			if (maps[nextY][nextX] == '#') return true;
			else if (maps[nextY][nextX] == '0')
			{
				q.push(make_pair(nextY, nextX));
				visited[nextY][nextX] = true;
			}
			else if (maps[nextY][nextX] == '1')
			{
				maps[nextY][nextX] = '0';
				visited[nextY][nextX] = true;
			}
		}
	}
	
	return false;
}

int main()
{
	cin >> N >> M >> ay >> ax >> by >> bx;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++)
			maps[i][j] = tmp[j];
	}

	while (!bfs())
	{		
		fill(&visited[0][0], &visited[0][0] + 300 * 300, false);
		ret++;
	}
	
	cout << ret;
}