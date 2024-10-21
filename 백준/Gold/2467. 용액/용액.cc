#include <bits/stdc++.h>
using namespace std;

long long N, a[100000], l, mid, r, ans = 2000000000;
pair<long long, long long> ret; 

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	
	for (int i = 0; i < N; i++)
	{
		l = i + 1; r = N - 1;
		while (l <= r)
		{
			mid = (l + r) / 2;
			long long m = a[i] + a[mid];
			if (m == 0)
			{
				cout << a[i] << ' ' << a[mid];
				return 0;
			}
			else if (m < 0)
				l = mid + 1;
			else
				r = mid - 1;				
			
			if (abs(m) < ans)
			{
				ans = abs(m);
				ret.first = a[i];
				ret.second = a[mid];
			}			
		}		
	}
	
	cout << ret.first << ' ' << ret.second;	
}