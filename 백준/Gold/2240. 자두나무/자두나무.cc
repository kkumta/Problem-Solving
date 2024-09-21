#include <bits/stdc++.h>
using namespace std;

int T, W, ret;
int a[1000];
int d[1000][31][2];

// 시각, 이동횟수, 현재 위치 
int go(int t, int cnt, int pos) 
{
	if (cnt > W || t == T) return 0;
	if (d[t][cnt][pos] != -1) return d[t][cnt][pos];
	
	return d[t][cnt][pos] = max(go(t + 1, cnt + 1, (pos + 1) % 2), go(t + 1, cnt, pos)) + (a[t] == pos);
}

int main()
{
	cin >> T >> W;
	for (int i = 0; i < T; i++)
	{
		cin >> a[i];
		a[i]--;		
	}	
	fill(&d[0][0][0], &d[0][0][0] + 1000 * 30 * 2, -1);
	
	cout << max(go(0, 0, 0), go(0, 1, 1));
}