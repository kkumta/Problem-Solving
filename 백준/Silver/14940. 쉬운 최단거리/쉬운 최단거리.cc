#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

int n, m;
int map[1000][1000];
int dist[1000][1000];
pair<int, int> target;

pair<int, int> dxy[] = { {0,1}, {1, 0}, {-1, 0}, {0,-1} };

void Bfs()
{
	queue<pair<int, int>> q;
	q.push(target);
	while (!q.empty())
	{
		pair<int, int> curPos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> nextPos = make_pair(curPos.first + dxy[i].first, curPos.second + dxy[i].second);

			// 유효하지 않은 좌표
			if (n <= nextPos.first || nextPos.first < 0 || m <= nextPos.second || nextPos.second < 0)
				continue;

			// 원래 갈 수 없는 땅이거나 이미 가본 땅이라면
			if (dist[nextPos.first][nextPos.second] != -1)
				continue;

			dist[nextPos.first][nextPos.second] = dist[curPos.first][curPos.second] + 1;
			q.push(nextPos);
		}
	}
}

int main()
{
	cin >> n >> m;

	memset(dist, -1, 1000000 * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0) // 원래 갈 수 없는 땅 설정
				dist[i][j] = 0;
			if (map[i][j] == 2) // 목표 지점 설정
			{
				target = make_pair(i, j);
				dist[i][j] = 0;
			}
		}
	}

	Bfs();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}