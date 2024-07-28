#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
	cin >> N;
	
	for (int i = N - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
			cout << ' ';
		for (int j = i * 2; j < N * 2 - 1; j++)
			cout << '*';
		cout << '\n';
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
			cout << ' ';
		for (int j = i * 2; j < N * 2 - 1; j++)
			cout << '*';
		cout << '\n';
	}	
}