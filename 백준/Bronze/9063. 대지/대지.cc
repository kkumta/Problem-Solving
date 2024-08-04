#include <bits/stdc++.h>
using namespace std;

int N;
long long x, y, maxX = -100000, maxY = -100000, minX = 100000, minY = 100000;

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		minX = min(minX, x);
		maxX = max(maxX, x);
		minY = min(minY, y);
		maxY = max(maxY, y);
	}
	
	cout << (maxX - minX) * (maxY - minY);
}