#include <bits/stdc++.h>
using namespace std;

int N, M, maxCnt;
vector<int> computers[10001];
bool visited[10001];
vector<pair<int, int>> hackingCnt;

int Dfs(int start)
{
	int ret = 1;
	visited[start] = true;
	
	for (int computer : computers[start])
	{
		if (visited[computer]) continue;
		ret += Dfs(computer);
	}
	
	return ret;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		computers[b].push_back(a);
	}
	
	for (int i = 0; i <= N; i++)
	{
		hackingCnt.push_back(make_pair(i, 0));
	}
	
	for (int i = 1; i <= N; i++)
	{
		fill(&visited[0], &visited[0] + 10001, false);
		hackingCnt[i].second = Dfs(i);
		maxCnt = max(hackingCnt[i].second, maxCnt);
	}
	
	sort(hackingCnt.begin(), hackingCnt.end(), cmp);
	for (pair<int, int> computer : hackingCnt)
	{
		if (computer.second < maxCnt) break;
		cout << computer.first << ' ';
	}
}