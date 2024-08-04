#include <bits/stdc++.h>
using namespace std;

int a[3];

int main()
{
	while (true)
	{
		cin >> a[0] >> a[1] >> a[2];
		if (a[0] == 0) break;
		
		sort(&a[0], &a[0] + 3);
		if (a[0] + a[1] <= a[2]) cout << "Invalid\n";
		else if (a[0] == a[1] && a[1] == a[2]) cout << "Equilateral\n";
		else if (a[0] == a[1] || a[0] == a[2] || a[1] == a[2]) cout << "Isosceles\n";
		else cout << "Scalene\n";
	}
}