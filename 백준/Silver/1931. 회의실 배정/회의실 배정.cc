#include <bits/stdc++.h>
using namespace std;

int N, a, b, curTime, ret;
vector<pair<int, int>> v;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(b, a));
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < N; i++)
	{
		if (curTime <= v[i].second)
		{
			curTime = v[i].first;
			ret++;
		}
	}
	
	cout << ret;
}