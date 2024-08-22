#include <bits/stdc++.h>
using namespace std;

int N, L, idx = -1000000000, ret;
vector<pair<int, int>> v;

int main()
{
	cin >> N >> L;
	v.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	
	sort(v.begin(), v.end());
	
	for (int i = 0; i < N; i++)
	{
		if (v[i].first >= idx + L + 1)
		{
			ret++;
			idx = v[i].first;
		}
		while (v[i].second >= idx + L + 1)
		{
			ret++;
			idx += L;
		}
	}
	
	cout << ret;
}