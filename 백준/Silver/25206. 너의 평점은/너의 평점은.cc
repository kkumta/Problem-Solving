#include <bits/stdc++.h>
using namespace std;

const int cnt = 20;
double a, aSum, bSum;
string tmp, b;

int main()
{
	for (int i = 0; i < cnt; i++)
	{
		cin >> tmp >> a >> b;
		if (b == "P") continue;
		
		aSum += a;
		if (b == "A+") bSum += a * 4.5;
		else if (b == "A0") bSum += a * 4.0;
		else if (b == "B+") bSum += a * 3.5;
		else if (b == "B0") bSum += a * 3.0;
		else if (b == "C+") bSum += a * 2.5;
		else if (b == "C0") bSum += a * 2.0;
		else if (b == "D+") bSum += a * 1.5;
		else if (b == "D0") bSum += a * 1.0;
	}
	
	cout << bSum / aSum;
}