#include <iostream>
using namespace std;
#include <vector>

int numberOfComputers, numberOfPairs;
vector<vector<int>> adj;
vector<bool> visited;
int ans = -1;

void Dfs(int here);

int main()
{
	cin >> numberOfComputers;
	cin >> numberOfPairs;
	adj = vector<vector<int>>(numberOfComputers + 1);
	for (int i = 0; i < numberOfPairs; i++)
	{
		int first, second;
		cin >> first >> second;
		adj[first].push_back(second);
		adj[second].push_back(first);
	}

	visited = vector<bool>(numberOfComputers + 1, false);
	Dfs(1);

	cout << ans;
}

void Dfs(int here)
{
	visited[here] = true;
	ans++;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (!visited[there])
			Dfs(there);
	}
}