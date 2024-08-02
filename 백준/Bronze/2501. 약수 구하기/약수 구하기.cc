#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> v;

int main()
{
	cin >> N >> K;
	
	v.push_back(1);
	for (int i = 2; i <= N; i++)
	{
		if (N % i == 0)
			v.push_back(i);
	}
	
	if (v.size() >= K)
		cout << v[K - 1];
	else
		cout << 0;
}