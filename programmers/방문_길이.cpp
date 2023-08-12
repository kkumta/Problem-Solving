#include <string>
#include <memory.h>
#include <cmath>

using namespace std;

int solution(string dirs)
{
	int ans = 0;

	bool visited[2][11][10];
	memset(visited, false, sizeof(visited));

	pair<int, int> curPos = make_pair(5, 5);
	for (int i = 0; i < dirs.size(); i++)
	{
		pair<int, int> nextPos = curPos;
		int first = 0; // 행 or 열
		int second = 0; // 행이 이동했으면 열의 값, 열이 이동했으면 행의 값
		int third = 0; // 행이 이동했으면 이동한 행의 길, 열이 이동했으면 이동한 열의 길
		switch (dirs[i])
		{
			case('U'):
				nextPos.first++;
				second = nextPos.second;
				third += min(curPos.first, nextPos.first);
				break;
			case('L'):
				nextPos.second--;
				first++;
				second = nextPos.first;
				third += min(curPos.second, nextPos.second);
				break;
			case('R'):
				nextPos.second++;
				first++;
				second = nextPos.first;
				third = min(curPos.second, nextPos.second);
				break;
			case('D'):
				nextPos.first--;
				second = nextPos.second;
				third = min(curPos.first, nextPos.first);
				break;
		}

		if (10 < nextPos.first || nextPos.first < 0)
			continue;
		if (10 < nextPos.second || nextPos.second < 0)
			continue;

		if (!visited[first][second][third])
		{
			visited[first][second][third] = true;
			ans++;
		}

		curPos = nextPos;
	}

	return ans;
}