#include <bits/stdc++.h>
using namespace std;

long long A, B, C;
long long ret;

long long func(long long b)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return A % C;
	
	long long d = func(b / 2);
	
	if (b % 2 == 0)
		return d * d % C;
	else
		return (d * d % C) * A % C;
}

int main()
{
	cin >> A >> B >> C;
	cout << func(B);
	return 0;
}