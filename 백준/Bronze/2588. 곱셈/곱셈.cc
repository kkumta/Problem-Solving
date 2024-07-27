#include <bits/stdc++.h>
using namespace std;

int a, b;
int ret1, ret2, ret3, ret4;

int main()
{
	cin >> a >> b;
	ret1 = a * (b % 10);
	ret2 = a * ((b % 100) / 10);
	ret3 = a * (b / 100);
	ret4 = a * b;
	
	cout << ret1 << '\n' << ret2 << '\n' << ret3 << '\n' << ret4;
}