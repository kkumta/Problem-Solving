#include <bits/stdc++.h>
using namespace std;

int N, len = 1, idx;
int A[1000], d[1000], p[1000];
stack<int> stk;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	fill(d, d + N, 1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i] && d[j] + 1 > d[i])
			{
				d[i] = d[j] + 1;
				p[i] = j;
				len = max(d[i], len);
			}
		}
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if (d[i] == len)
		{
			idx = i;
			break;
		}
	}

	cout << len << '\n';	
	while (len != 0)
	{
		stk.push(A[idx]);
		idx = p[idx];
		len--;
	}
	
	while (!stk.empty())
	{
		cout << stk.top() << ' ';
		stk.pop();
	}
}