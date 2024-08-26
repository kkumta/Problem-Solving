#include <bits/stdc++.h>
using namespace std;

int maps[1000], a[10], b[10], pos[4], sum[4];
int ret;

void func1()
{
	pos[0] = pos[1] = pos[2] = pos[3] = 0;
	sum[0] = sum[1] = sum[2] = sum[3] = 0;
	for (int i = 0; i < 10; i++)
	{
		int j = b[i]; // 이번 턴에 이동할 말의 이름
		pos[j] += a[i];
		if (pos[j] == 5) pos[j] = 113;
		else if (pos[j] == 10) pos[j] = 214;
		else if (pos[j] == 15) pos[j] = 313;
		for (int k = 0; k < 4; k++)
		{
			if (k == j) continue;
			if (pos[j] == pos[k]) return;
			if (pos[j] == 113 && pos[k] == 5) return;
			if (pos[j] == 214 && pos[k] == 10) return;
			if (pos[j] == 313 && pos[k] == 15) return;
			if (pos[j] == 117 && (pos[k] == 217 || pos[k] == 317)) return;
			if (pos[j] == 217 && (pos[k] == 117 || pos[k] == 317)) return;
			if (pos[j] == 317 && (pos[k] == 117 || pos[k] == 217)) return;
			if (pos[j] == 118 && (pos[k] == 218 || pos[k] == 318)) return;
			if (pos[j] == 218 && (pos[k] == 118 || pos[k] == 318)) return;
			if (pos[j] == 318 && (pos[k] == 118 || pos[k] == 218)) return;
			if (pos[j] == 119 && (pos[k] == 219 || pos[k] == 319)) return;
			if (pos[j] == 219 && (pos[k] == 119 || pos[k] == 319)) return;
			if (pos[j] == 319 && (pos[k] == 119 || pos[k] == 219)) return;
			if (pos[j] == 20 && (pos[k] == 120 || pos[k] == 220 || pos[k] == 320)) return;
			if (pos[j] == 120 && (pos[k] == 20 || pos[k] == 220 || pos[k] == 320)) return;
			if (pos[j] == 220 && (pos[k] == 20 || pos[k] == 120 || pos[k] == 320)) return;
			if (pos[j] == 320 && (pos[k] == 20 || pos[k] == 120 || pos[k] == 220)) return;	
		} 
		sum[j] += maps[pos[j]];
	}
	
	ret = max(sum[0] + sum[1] + sum[2] + sum[3], ret);
}

void func2(int k)
{
	if (k == 10)
	{
		func1();
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		b[k] = i;
		func2(k + 1);
	}
}

int main()
{
	for (int i = 1; i <= 20; i++)
		maps[i] = i * 2;
	maps[113] = 10;
	maps[114] = 13;
	maps[115] = 16;
	maps[116] = 19;
	maps[214] = 20;
	maps[215] = 22;
	maps[216] = 24;
	maps[313] = 30;
	maps[314] = 28;
	maps[315] = 27;
	maps[316] = 26;
	maps[117] = maps[217] = maps[317] = 25;
	maps[118] = maps[218] = maps[318] = 30;
	maps[119] = maps[219] = maps[319] = 35;
	maps[120] = maps[220] = maps[320] = 40;	
	
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	
	func2(0);
	cout << ret;
}