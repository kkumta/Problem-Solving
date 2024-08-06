#include <bits/stdc++.h>
using namespace std;

int N, a, b, ret;
vector<pair<int, int>> v; // 데드라인, 컵라면 수
priority_queue<int, vector<int>, greater<int>> pq; // 컵라면 수 기준 

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < N; i++)
	{
		pq.push(v[i].second);
		if (pq.size() > v[i].first)
			pq.pop();
	}
	
	while (!pq.empty())
	{
		ret += pq.top();
		pq.pop();
	}
	
	cout << ret;
}