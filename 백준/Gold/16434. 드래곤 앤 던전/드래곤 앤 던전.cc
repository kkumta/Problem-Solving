#include <bits/stdc++.h>
using namespace std;

struct Room
{
	long long t, a, h;
};

int N;
long long atk, maxHp = LLONG_MAX / 2, l = 1, r = LLONG_MAX / 2, mid;
Room room[123456];

bool simulate(long long target)
{
	long long curHp = target, curAtk = atk;
	for (int i = 0; i < N; i++)
	{
		if (room[i].t == 1)
		{
			long long curMonsterHp = room[i].h;
			long long cnt = curMonsterHp / curAtk;
			if (curMonsterHp % curAtk != 0) cnt++;
			if (room[i].a * (cnt - 1) >= curHp) return false;
			else curHp -= room[i].a * (cnt - 1);
		}
		else
		{
			if (curHp + room[i].h >= target) curHp = target;
			else curHp += room[i].h;
			curAtk += room[i].a;
		}
	}
	
	return true;
}

int main()
{
	cin >> N >> atk;
	for (int i = 0; i < N; i++)
		cin >> room[i].t >> room[i].a >> room[i].h;
		
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (simulate(mid))
		{
			maxHp = min(mid, maxHp);
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	
	cout << maxHp;
}