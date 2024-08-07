#include <bits/stdc++.h>
using namespace std;

int N, K, m, v, c;
long long ret;
vector<pair<int, int>> vmv;
vector<int> vc;
priority_queue<int> pq;

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> m >> v;
		vmv.push_back(make_pair(m, v));
	}
	for (int i = 0; i < K; i++)
	{
		cin >> c;
		vc.push_back(c);
	}
	sort(vmv.begin(), vmv.end());
	sort(vc.begin(), vc.end());
	
	for (int i = 0, j = 0; i < K; i++)
	{
		while (j < N && vmv[j].first <= vc[i])
		{
			pq.push(vmv[j].second); j++;
		}
		
		if (!pq.empty())
		{
			ret += pq.top(); pq.pop();
		}
	}
	
	cout << ret;
}