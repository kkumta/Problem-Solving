#include <bits/stdc++.h>
using namespace std;

int T, N, M, a, b, flag;
bool edges[1001][1001], usedEdges[1001][1001], visitedNodes[1001];

void dfs(int node)
{
	if (visitedNodes[node])
	{
		flag = false;
		return;
	}
	visitedNodes[node] = true;
	
	for (int i = 1; i <= N; i++)
	{
		if (i == node) continue;
		if (edges[node][i] && !usedEdges[node][i])
		{
			usedEdges[node][i] = true;
			usedEdges[i][node] = true;
			dfs(i);	
		}
	}
}

void check()
{
	for (int i = 1; i <= N; i++)
		if (!visitedNodes[i])
		{
			flag = false;
			return;
		}
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		flag = true;
		fill(&edges[0][0], &edges[0][0] + 1001 * 1001, false);
		cin >> N >> M;
		for (int j = 0; j < M; j++)
		{
			cin >> a >> b;
			if (edges[a][b]) flag = false;
			edges[a][b] = true;
			edges[b][a] = true;
		}
	
		for (int j = 1; j <= N; j++)
		{
			fill(&usedEdges[0][0], &usedEdges[0][0] + 1001 * 1001, false);
			fill(&visitedNodes[0], &visitedNodes[0] + 1001, false);
			dfs(j);
			check();
			if (!flag) break;
		}
		
		flag ? cout << "tree\n" : cout << "graph\n";
	}
}