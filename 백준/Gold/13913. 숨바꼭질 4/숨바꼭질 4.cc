#include <bits/stdc++.h>
using namespace std;

int N, K;
const int MAX = 3000000;
int visited[3000010], pre[3000010];
pair<int, vector<int>> ret;

void bfs(int start, int end)
{
	queue<int> visitedQueue;
	visitedQueue.push(start);
	visited[start] = 1;
	
	while (!visitedQueue.empty())
	{		
		int curPos = visitedQueue.front(); visitedQueue.pop();		
		if (curPos == K)
			return;
		
		for (int nextPos : {curPos - 1, curPos + 1, curPos * 2})
		{
			if (nextPos >= 0 && nextPos <= MAX)
			{
				if (visited[nextPos] == 0)
				{
					visited[nextPos] = visited[curPos] + 1;
					visitedQueue.push(nextPos);
					
					pre[nextPos] = curPos;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	
	if (N == K)
	{
		cout << 0 << '\n' << K;
		return 0;
	}
	
	bfs(N, K);
	ret.first = visited[K] - 1;
	
	for (int pos = K; pos != N; pos = pre[pos])
		ret.second.push_back(pos);
	ret.second.push_back(N);
	reverse(ret.second.begin(), ret.second.end());
	
	cout << ret.first << '\n';
	for (int pos : ret.second)
		cout << pos << ' ';
}