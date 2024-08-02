#include <bits/stdc++.h>
using namespace std;

int n, sum;
vector<int> v;

int main()
{
	while (true)
	{
		cin >> n;
		if (n == -1) return 0;
		
		v.clear(); sum = 0;
		for (int i = 1; i < n; i++)
			if (n % i == 0)
				v.push_back(i);
		
		for (int i : v)
			sum += i;
			
		if (sum == n)
		{
			cout << n << " = ";
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i];
				if (i != v.size() - 1) cout << " + ";
			}
		}
		else
			cout << n << " is NOT perfect.";
		cout << '\n';
	}
}