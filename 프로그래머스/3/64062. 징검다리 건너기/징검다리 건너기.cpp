#include <bits/stdc++.h>
using namespace std;

int ret, l = 1, mid, r;

// 완전탐색: 무제한 * 20만이라 불가능
// dp: 점화식이 안 떠오름
// 이분탐색: 매개변수를 니니즈 수로 할 수는 없음 -> 니니즈 수로 하는 거 맞음...

int solution(vector<int> stones, int k)
{
    for (int i : stones)
        r = max(i, r);
    
    while (l <= r)
    {
        int mid = (l + r) / 2;
        
        bool flag = true;
        int cnt = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            if (stones[i] < mid)
            {
                cnt++;
                if (cnt == k) flag = false;
            }
            else cnt = 0;
        }
        
        if (flag)
        {
            ret = max(mid, ret);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    
    return ret;
}