#include <bits/stdc++.h>
using namespace std;

long long A, B, C;
long long ret;

long long func(long long b)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return A;
	
	if (b % 2 == 0)
		return func(b / 2) * func(b / 2) % C;
	else
		return (func(b / 2) * func(b / 2) % C) * A % C;
}

int main()
{
	cin >> A >> B >> C;
	cout << func(B) % C;
	return 0;
}