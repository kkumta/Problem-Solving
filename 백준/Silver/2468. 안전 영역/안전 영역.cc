#include <iostream>
#include <vector>
using namespace std;

void search(pair<int, int> here, int height);

int n, answer = 1; // 비가 오지 않는 경우 1개의 안전한 영역이 존재한다.
vector<vector<int>> map;
vector<vector<bool>> visited;

vector<pair<int, int>> dxy = { {0,1}, {1, 0}, {-1, 0}, {0, -1} };

int main()
{
	// map 초기화
	cin >> n;
	map = vector<vector<int>>(n);
	for (int i = 0; i < n; i++)
		map[i] = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	// visited 초기화
	visited = vector<vector<bool>>(n);
	for (int i = 0; i < n; i++)
		visited[i] = vector<bool>(n);

	// 안전한 영역의 개수 구하기
	for (int height = 1; height <= 100; height++)
	{
		fill(visited.begin(), visited.end(), vector<bool>(n, false)); // visited 초기화
		int count = 0; // 높이가 height일 때 안전한 영역의 개수
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				if (map[row][col] > height && !visited[row][col])
				{
					search(make_pair(row, col), height);
					count++;
				}
			}
		}

		if (count > answer)
			answer = count;
	}

	cout << answer;
}

void search(pair<int, int> here, int height)
{
	visited[here.first][here.second] = true;
	for (int i = 0; i < dxy.size(); i++)
	{
		pair<int, int> there = make_pair(here.first + dxy[i].first, here.second + dxy[i].second);

		if (n <= there.first || there.first < 0 || n <= there.second || there.second < 0)
			continue;
		if (map[there.first][there.second] <= height)
			continue;
		if (visited[there.first][there.second])
			continue;

		search(there, height);
	}
}