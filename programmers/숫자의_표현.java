class Solution {
    public int solution(int n) {
        int[] d = new int[n + 1];
        d[0] = 0;
        for (int i = 1; i <= n; i++) {
            d[i] = d[i - 1] + i;
        }
        
        int ans = 0;
        for (int start = 0; start < n; start++) {
            for (int end = start + 1; end <= n; end++) {
                if (d[end] - d[start] == n) {
                    ans++;
                    break;
                } else if (d[end] - d[start] > n) {
                    break;
                }
            }
        }
        
        return ans;
    }
}