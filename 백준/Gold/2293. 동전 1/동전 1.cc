#include <bits/stdc++.h>
using namespace std;

int n, k, tmp;
int d[10001];

int main()
{
	cin >> n >> k;
	
	d[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		for (int j = tmp; j <= k; j++) d[j] += d[j - tmp];
	}
	
	cout << d[k];
}