#include <bits/stdc++.h>
using namespace std;

int N, a = 2, n = 1, ret = 4;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		ret += n;
		ret += n * 2;
		ret += a;
		
		a *= 2;
		n *= 4;
	}
	
	cout << ret;
}