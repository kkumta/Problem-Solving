#include <bits/stdc++.h>
using namespace std;

string A, B;
int a, b;

int main()
{
	cin >> A >> B;
	a = (A[2] - '0') * 100 + (A[1] - '0') * 10 + A[0] - '0';
	b = (B[2] - '0') * 100 + (B[1] - '0') * 10 + B[0] - '0';
	a > b ? cout << a : cout << b;
}