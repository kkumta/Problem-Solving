#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{	
	while (cin >> n)
	{
		long long cnt = 1, ret = 1;
		while (cnt % n != 0)
		{
			cnt = cnt * 10 + 1;
			cnt %= n;
			ret++;
		}
		
		cout << ret << '\n';
	}
}