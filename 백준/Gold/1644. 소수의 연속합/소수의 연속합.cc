#include <bits/stdc++.h>
using namespace std;

int N, s, e, sum, ret;
vector<int> v;

int main()
{
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		bool flag = true;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag) v.push_back(i);
	}
	
	for (; s < v.size() && e < v.size(); )
	{
		sum += v[e];
		if (sum < N)
		{
			e++;
			continue;
		}
		else if (sum == N) ret++;
		s++;
		e = s;
		sum = 0;
	}
	
	cout << ret;
}