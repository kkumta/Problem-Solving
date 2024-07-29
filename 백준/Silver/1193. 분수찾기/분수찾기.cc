#include<bits/stdc++.h>
using namespace std;

int cnt = 1, X, a = 1, b = 1;
bool flag;

int main()
{
	cin >> X;
	while (true)
	{
		if (flag)
			for (int i = 1, j = b; i <= a && j >= 1; i++, j--)
			{
				if (cnt == X)
				{
					cout << i << '/' << j;
					return 0;
				}
				cnt++;					
			}		
		else
			for (int i = a, j = 1; i >= 1 && j <= b; i--, j++)
			{
				if (cnt == X)
				{
					cout << i << '/' << j;
					return 0;
				}
				cnt++;					
			}		
		
		flag = !flag;
		a++; b++;
	}
}