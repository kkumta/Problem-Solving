#include <bits/stdc++.h>
using namespace std;

int N, minValue = 1000000000, maxValue = -1000000000;
int a[11];
char b[10], oper[10];
bool isUsed[10];
char opers[4] = {'+', '-', '*', '/'};

void calc()
{	
	int result = a[0];
	for (int i = 0; i < N - 1; i++)
	{
		switch (oper[i])
		{
			case '+':
			{
				result += a[i + 1];
				break;
			}
			case '-':
			{
				result -= a[i + 1];
				break;
			}
			case '*':
			{
				result *= a[i + 1];
				break;
			}
			case '/':
			{
				result /= a[i + 1];
				break;
			}
		}
	}

	minValue = min(result, minValue);
	maxValue = max(result, maxValue);
}

void go(int k)
{
	if (k == N - 1)
	{
		calc();
		return;
	}
	
	for (int i = 0; i < N - 1; i++)
	{
		if (!isUsed[i])
		{
			isUsed[i] = true;
			oper[k] = b[i];
			go(k + 1);
			isUsed[i] = false;			
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int idx = 0, i = 0; i < 4; i++)
	{
		int tmp;
		cin >> tmp;
		for (int j = 0; j < tmp; j++)
			b[idx++] = opers[i];
	}
	
	go(0);
	
	cout << maxValue << '\n' << minValue; 
}