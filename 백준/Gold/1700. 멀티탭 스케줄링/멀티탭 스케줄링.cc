#include <bits/stdc++.h>
using namespace std;

int N, K, ret;
int a[101];
bool visited[101];
vector<int> v;

int main()
{
	cin >> N >> K;
	for (int i = 0; i < K; i++)
		cin >> a[i];
	
	for (int i = 0; i < K; i++)
	{		
		if (visited[a[i]]) continue; // 멀티탭에 이미 꽂혀있다면 
		if (v.size() < N) // 멀티탭에 자리가 남아있다면 
		{
			visited[a[i]] = true;
			v.push_back(a[i]);
		}
		else // 멀티탭에 자리가 남아있지 않다면 
		{
			// 콘센트에 꽂혀 있는 전기용품 중 앞으로 콘센트를 쓸 필요가 없으면 교체
			// 콘센트에 꽂혀 있는 모든 전기용품이 앞으로 콘센트를 써야 하면 가장 나중에 다시 쓰이는 것으로 교체 
			ret++;
			int maxIdx = -1, name = 0;
			for (int j : v)
			{
				bool nextExist = false;
				for (int k = i + 1; k < K; k++)
				{
					if (a[k] == j)
					{
						if (k > maxIdx)
						{
							maxIdx = k;
							name = a[k];
						}
						nextExist = true;
						break;
					}
				}
				if (!nextExist)
				{
					name = j;
					break;
				}
			}
		
			v.erase(find(v.begin(), v.end(), name));
			visited[name] = false;
			
			v.push_back(a[i]);
			visited[a[i]] = true;
		}
	}
	
	cout << ret;
}