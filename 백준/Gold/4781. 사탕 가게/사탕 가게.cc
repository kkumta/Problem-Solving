#include <bits/stdc++.h>
using namespace std;

int n, c, pr;
double m, p;
int d[10001];

int main()
{
	while (true)
	{
		cin >> n >> m;
		if (n == 0) break;
		
		fill(d, d + 10001, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> c >> p;
			pr = (int)(p * 100 + 0.5);
			for (int j = pr; j <= (int)(m * 100 + 0.5); j++)
				d[j] = max(d[j - pr] + c, d[j]);
		}
		
		cout << d[(int)(m * 100 + 0.5)] << '\n';
	}
}