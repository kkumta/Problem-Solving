#include <bits/stdc++.h>
using namespace std;

int x;
int d[1000001];
stack<int> stk;

int main()
{
	cin >> x;
	fill(d, d + 1000001, 1000000);
	d[x] = 0;
	
	for (int i = x; i > 0; i--)
	{
		if (i % 3 == 0) d[i / 3] = min(d[i] + 1, d[i / 3]);
		if (i % 2 == 0) d[i / 2] = min(d[i] + 1, d[i / 2]);
		d[i - 1] = min(d[i] + 1, d[i - 1]);
	}
	cout << d[1] << '\n';
	
	for (int i = 1; i <= x; )
	{
		stk.push(i);
		if (i * 3 <= 1000000 && d[i * 3] == d[i] - 1) i *= 3;
		else if (i * 2 <= 1000000 && d[i * 2] == d[i] - 1) i *= 2;
		else i++;
	}
	
	while (!stk.empty())
	{
		cout << stk.top() << ' ';
		stk.pop();
	}
}