#include <bits/stdc++.h>
using namespace std;

int N;
double a[10000], d[10000];
double ret;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		d[i] = a[i];
	}
	
	for (int i = 1; i < N; i++)
		d[i] = max(d[i - 1] * a[i], d[i]);
	
	for (int i = 0; i < N; i++)
		ret = max(d[i], ret);
	
	cout << fixed;
	cout.precision(3);
	cout << ret;
}