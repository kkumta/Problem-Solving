#include <bits/stdc++.h>
using namespace std;

long long A, B, V;
int ret;

int main()
{
	cin >> A >> B >> V;
	
	ret = (V - B) / (A - B);
	if ((V - B) % (A - B) != 0) ret++;
	
	cout << ret;
}