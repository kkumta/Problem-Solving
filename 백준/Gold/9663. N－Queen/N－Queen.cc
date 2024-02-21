#include <queue>
#include <iostream>
using namespace std;

int N, ans;
bool isUsed[15][15];

void Func(int k)
{
	if (k == N)
	{
		ans++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (isUsed[k][i])
			continue;
		// 퀸을 [k][i]에 뒀을 때 그 퀸이 갈 수 있는 위치 중 isUsed가 false인 위치를 큐에 담고 true로 변경
		queue<pair<int, int>> q;
		if (!isUsed[k][i])
		{
			q.push(make_pair(k, i));
			isUsed[k][i] = true;
		}
		for (int j = 1; j < N - k; j++)
		{
			// 같은 열 true로 변경
			if (!isUsed[k + j][i])
			{
				q.push(make_pair(k + j, i));
				isUsed[k + j][i] = true;
			}
			// 좌측 대각선 true로 변경
			if (i - j >= 0 && !isUsed[k + j][i - j])
			{
				q.push(make_pair(k + j, i - j));
				isUsed[k + j][i - j] = true;
			}
			// 우측 대각선 true로 변경
			if (i + j < N && !isUsed[k + j][i + j])
			{
				q.push(make_pair(k + j, i + j));
				isUsed[k + j][i + j] = true;
			}
		}
		Func(k + 1); // 다음 행 탐색
		// 큐에 담긴 위치를 false로 변경
		while (!q.empty())
		{
			pair<int, int> pos = q.front();
			isUsed[pos.first][pos.second] = false;
			q.pop();
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	Func(0);
	cout << ans;
}