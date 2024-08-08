#include <bits/stdc++.h>
using namespace std;

int N, s, e;
long long ret;
int a[100000];
bool used[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
		
	for (; s < N;)
	{
		if (used[a[e]] || e == N)
		{
			s++;
			ret += e - s;
			used[a[s - 1]] = false;
		} 
		else
		{
			used[a[e]] = true;
			e++;
			ret++;
		}
	}
	
	cout << ret;
}