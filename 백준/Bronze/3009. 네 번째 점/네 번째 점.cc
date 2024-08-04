#include <bits/stdc++.h>
using namespace std;

int a1, a2, b1, b2, c1, c2, ret1, ret2;

int main()
{
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
	
	if (a1 == b1) ret1 = c1;
	else if (a1 == c1) ret1 = b1;
	else ret1 = a1;
	
	if (a2 == b2) ret2 = c2;
	else if (a2 == c2) ret2 = b2;
	else ret2 = a2;
	
	cout << ret1 << ' ' << ret2;
}