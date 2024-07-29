#include <bits/stdc++.h>
using namespace std;

const int cnt = 5;
string tmp;
char a[5][15];

int main()
{
	for (int i = 0; i < cnt; i++)
	{
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++)
			a[i][j] = tmp[j];
	}
	
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < cnt; j++)
		{
			if (a[j][i] == 0) continue;
			cout << a[j][i];
		}
	}
}