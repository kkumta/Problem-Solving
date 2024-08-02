#include <bits/stdc++.h>
using namespace std;

int N, ret;

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		if (n == 1) continue;
		
		bool flag = true;
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				flag = false;
				break;
			}
		}
		
		if (flag) ret++;
	}
	
	cout << ret;
}