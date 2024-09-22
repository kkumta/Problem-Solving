#include <bits/stdc++.h>
using namespace std;

long long n;
long long d[31][31];

// a: 약병에 남은 1개짜리 개수, b: 약병에 남은 반 개짜리 개수 
long long go(int w, int h)
{
	if (w == 0 && h == 0)
		return 1;
	if (w < 0 || h < 0)
		return 0;
	
	if (d[w][h]) return d[w][h];
	
	if (w == 0)
		return d[w][h] = go(w, h - 1);
	else if (h == 0)
		return d[w][h] = go(w - 1, h + 1);
		
	return d[w][h] = go(w, h - 1) + go(w - 1, h + 1);
}

int main()
{
	while (true)
	{
		cin >> n;
		if (n == 0) return 0;
		
		cout << go(n, 0) << '\n';	
	}
}