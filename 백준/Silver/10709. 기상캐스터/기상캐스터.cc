#include <bits/stdc++.h>
using namespace std;

int H, W;
int visited[100][100];
queue<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int nextY = q.front().first;
		int nextX = q.front().second + 1;
		q.pop();
		
		if (nextX < 0 || nextX >= W) continue;
		if (visited[nextY][nextX] != -1) continue;
		
		visited[nextY][nextX] = visited[nextY][nextX - 1] + 1;
		q.push(make_pair(nextY, nextX));
	}
}

int main()
{
	fill(&visited[0][0], &visited[0][0] + 100 * 100, -1);
	
	cin >> H >> W;
	for (int i = 0; i < H; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < W; j++)
		{
			if (tmp[j] == 'c')
			{
				visited[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}
	
	bfs();
	
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
}