#include <bits/stdc++.h>
using namespace std;

int N, a, b;
long long X, sum;

int main()
{
	cin >> X >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		sum += a * b;
	}
	
	if (X == sum) cout << "Yes";
	else cout << "No";
}