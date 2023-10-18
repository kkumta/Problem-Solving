#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int height, width;
int arrayMap[100][100];
bool visited[100][100];

pair<int, int> dxy[] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int Bfs(pair<int, int> start)
{
	int food = 0;

	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = true;
	while (!q.empty())
	{
		pair<int, int> curPos = q.front(); q.pop();
		food += arrayMap[curPos.first][curPos.second];
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> nextPos = { curPos.first + dxy[i].first, curPos.second + dxy[i].second };

			// 지도 범위에서 벗어난다
			if (height <= nextPos.first || nextPos.first < 0 || width <= nextPos.second || nextPos.second < 0)
				continue;

			// 바다이다
			if (arrayMap[nextPos.first][nextPos.second] == 0)
				continue;

			// 이미 탐색한 곳이다
			if (visited[nextPos.first][nextPos.second])
				continue;

			q.push(nextPos);
			visited[nextPos.first][nextPos.second] = true;
		}
	}

	return food;
}

vector<int> solution(vector<string> maps)
{
	height = maps.size();
	width = maps[0].size();

	// vector<string> -> int[][]
	for (int i = 0; i < height; i++)
	{
		string row = maps[i];
		for (int j = 0; j < width; j++)
		{
			if (row[j] == 'X')
				arrayMap[i][j] = 0;
			else
				arrayMap[i][j] = row[j] - '0';
		}
	}

	// 각 무인도의 식량 수 구하기
	vector<int> answer;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			// 바다가 아니면서 아직 탐색하지 않은 곳만 탐색
			if (arrayMap[i][j] != 0 && !visited[i][j])
				answer.push_back(Bfs(make_pair(i, j)));
		}
	}

	// 오름차순 정렬하기
	sort(answer.begin(), answer.end());

	if (answer.empty())
		answer.push_back(-1);

	return answer;
}