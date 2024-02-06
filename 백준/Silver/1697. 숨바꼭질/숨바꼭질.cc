#include <queue>
#include <iostream>
using namespace std;

int N, K;
int times[100001];

void bfs()
{
	queue<int> q;
	q.push(N);
	while (!q.empty())
	{
		int curPos = q.front(); q.pop();
		{
			int nextPos = curPos + 1;
			if (nextPos < 0 || nextPos > 100000);
			else if (times[nextPos] == 0)
			{
				times[nextPos] = times[curPos] + 1;
				q.push(nextPos);
			}
		}
		{
			int nextPos = curPos - 1;
			if (nextPos < 0 || nextPos > 100000);
			else if (times[nextPos] == 0)
			{
				times[nextPos] = times[curPos] + 1;
				q.push(nextPos);
			}
		}
		{
			int nextPos = curPos * 2;
			if (nextPos < 0 || nextPos > 100000);
			else if (times[nextPos] == 0)
			{
				times[nextPos] = times[curPos] + 1;
				q.push(nextPos);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	times[N] = 1;
	bfs();

	cout << times[K] - 1;
}