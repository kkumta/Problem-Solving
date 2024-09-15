#include <bits/stdc++.h>
using namespace std;

// LIS 사용 

int n, tmp1, tmp2, len;
vector< pair<int, int> > v;
int d[501];

int main()
{
	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		cin >> tmp1 >> tmp2;
		v.push_back(make_pair(tmp1, tmp2));
	}
	sort(v.begin(), v.end());
	
	// v.second(B 전봇대) 기준으로 LIS
	fill(d, d + 501, 1);
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i].second > v[j].second && d[j] + 1 > d[i])
			{
				d[i] = d[j] + 1;
				len = max(d[i], len);
			}
		}
	}
	
	cout << n - len;
}