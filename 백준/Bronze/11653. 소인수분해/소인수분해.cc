#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> pnums;

int main()
{
	cin >> N;
	
	while (N > 1)
	{
		for (int i = 2; i <= N; i++)
			if (N % i == 0)
			{
				N /= i;
				cout << i << '\n';
				break;
			}
	}
}