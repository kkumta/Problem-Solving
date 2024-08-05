#include <bits/stdc++.h>
using namespace std;

int n, d, p, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		v.push_back(make_pair(d, p));
	}
	sort(v.begin(), v.end()); // 1. day, 2. p를 기준으로 정렬 
	
	for (int i = 0; i < n; i++)
	{
		pq.push(v[i].second);
		if (pq.size() > v[i].first) // 현재 day 안에 pq에 있는 모든 강연을 할 수 없을 때 
			pq.pop(); // p가 가장 작은 강연 제거 
	}
	
	while (!pq.empty())
	{
		ret += pq.top();
		pq.pop();
	}
	
	cout << ret;
}