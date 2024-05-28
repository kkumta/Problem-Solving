#include <bits/stdc++.h>
using namespace std;

int N, M, ret;
int nums[15000];
bool existed[100001];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		existed[nums[i]] = true;
	}
	
	for (int i = 0; i < N; i++)
	{
		if (M - nums[i] > 100000 || M - nums[i] <= 0) continue;
		if (existed[M - nums[i]]) ret++;
	}
	
	cout << ret / 2;
}