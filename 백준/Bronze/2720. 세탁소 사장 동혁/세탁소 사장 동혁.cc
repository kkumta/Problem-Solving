#include <bits/stdc++.h>
using namespace std;

int T, C;
int ret[4];
const int a = 25, b = 10, c = 5, d = 01;

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> C;
		
		ret[0] = C / a;
		C %= a;
		
		ret[1] = C / b;
		C %= b;
		
		ret[2] = C / c;
		C %= c;
		
		ret[3] = C;
		
		cout << ret[0] << ' ' << ret[1] << ' ' << ret[2] << ' ' << ret[3] << '\n';
	}
}