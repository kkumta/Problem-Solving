#include <bits/stdc++.h>
using namespace std;

int A, B, C, ret;

int main()
{
	cin >> A >> B >> C;
	ret = A * 60 + B + C;
	ret %= 60 * 24;
	
	cout << ret / 60 << ' ' << ret % 60; 
}