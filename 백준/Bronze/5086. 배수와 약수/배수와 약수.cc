#include <bits/stdc++.h>
using namespace std;

int a, b;

int main()
{
	while (true)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			return 0;
		if (a > b && a % b == 0)
			cout << "multiple\n";
		else if (b > a && b % a == 0)
			cout << "factor\n";
		else
			cout << "neither\n";		
	}
}