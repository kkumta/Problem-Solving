#include <bits/stdc++.h>
using namespace std;

const int s1 = 100, s2 = 10;
bool paper[100][100];
int n, a, b, ret;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		for (int j = a; j < a + 10; j++)
		{
			for (int k = b; k < b + 10; k++)
				paper[j][k] = true;
		}
	}
	
	for (int i = 0; i < s1; i++)
		for (int j = 0; j < s1; j++)
			if (paper[i][j]) ret++;
			
	cout << ret;
}