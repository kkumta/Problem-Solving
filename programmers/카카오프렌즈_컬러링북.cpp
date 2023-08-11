#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

bool visited[100][100];
int dx[4];
int dy[4];

int bfs(int x, int y, vector<vector<int>> picture)
{
	int result = 0;
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty())
	{
		pair<int, int> curPos = q.front();
		q.pop();
		result++;

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> nextPos = { curPos.first + dx[i], curPos.second + dy[i] };

			if (picture.size() - 1 < nextPos.first || nextPos.first < 0)
			{
				continue;
			}
			if (picture[0].size() - 1 < nextPos.second || nextPos.second < 0)
			{
				continue;
			}
			if (visited[nextPos.first][nextPos.second])
			{
				continue;
			}
			if (picture[nextPos.first][nextPos.second] != picture[curPos.first][curPos.second])
			{
				continue;
			}

			visited[nextPos.first][nextPos.second] = true;
			q.push(nextPos);
		}
	}

	return result;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	int numberOfArea = 0;
	int maxSizeOfOneArea = 0;

	dx[0] = -1, dx[1] = 0, dx[2] = 1, dx[3] = 0;
	dy[0] = 0, dy[1] = -1, dy[2] = 0, dy[3] = 1;

	// visited 초기화
	memset(visited, false, sizeof(visited));

	// bfs 탐색
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && picture[i][j] != 0)
			{
				int curSize = bfs(i, j, picture);
				if (maxSizeOfOneArea < curSize)
				{
					maxSizeOfOneArea = curSize;
				}
				numberOfArea++;
			}
		}
	}

	vector<int> ans(2);
	ans[0] = numberOfArea;
	ans[1] = maxSizeOfOneArea;
	return ans;
}