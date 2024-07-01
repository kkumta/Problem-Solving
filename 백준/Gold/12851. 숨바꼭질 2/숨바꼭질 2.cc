#include <bits/stdc++.h>
using namespace std;

int N, K;
const int maxSize = 100000;
int visited[100001], cnt[100001];
pair<int, int> ret;

void bfs(int start, int end)
{
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	cnt[start] = 1;
	while (!q.empty())
	{		
		int curPos = q.front(); q.pop();
		for (int nextPos : {curPos - 1, curPos + 1, curPos * 2})
		{
			if (nextPos >= 0 && nextPos <= maxSize)
			{
				if (visited[nextPos] == 0)
				{
					visited[nextPos] = visited[curPos] + 1;
					cnt[nextPos] += cnt[curPos];
					q.push(nextPos);
				}
				else if (visited[nextPos] == visited[curPos] + 1)
					cnt[nextPos] += cnt[curPos];
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	
	bfs(N, K);
	ret.first = visited[K] - 1;
	ret.second = cnt[K];
	
	cout << ret.first << '\n' << ret.second;
}