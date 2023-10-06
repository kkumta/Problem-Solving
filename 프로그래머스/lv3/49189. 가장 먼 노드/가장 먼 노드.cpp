#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

vector<int> graph[20001];
int d[20001];

void Bfs()
{
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : graph[cur])
		{
			if (d[next] == -1)
			{
				d[next] = d[cur] + 1;
				q.push(next);
			}
		}
	}
}

int solution(int n, vector<vector<int>> edge)
{
	// 그래프 생성
	for (int i = 0; i < edge.size(); i++)
	{
		graph[edge[i][0]].push_back(edge[i][1]);
		graph[edge[i][1]].push_back(edge[i][0]);
	}

	// 각 정점까지의 거리 구하기
	memset(d, -1, (n + 1) * sizeof(int));
	d[1] = 0;
	Bfs();

	// 가장 먼 정점까지의 거리 구하기
	int maxDistance = 1;
	for (int i = 1; i <= n; i++)
		maxDistance = max(d[i], maxDistance);

	// 가장 먼 정점의 개수 구하기
	int answer = 0;
	for (int i = 1; i <= n; i++)
		if (d[i] == maxDistance) answer++;

	return answer;
}