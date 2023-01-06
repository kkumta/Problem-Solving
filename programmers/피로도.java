class Solution {
    
    boolean isVisited[];
    int ans = 0;
    
    public int solution(int k, int[][] dungeons) {
        isVisited = new boolean[dungeons.length];
        for (int i = 1; i <= dungeons.length; i++) {
            func(k, dungeons, 0, i);
        }
        
        return ans;
    }
    
    private void func(int k, int[][] dungeons, int cnt, int n) {
        if (cnt == n) {
            if (ans < cnt) {
                ans = cnt;
            }
            return;
        }
        
        for (int i = 0; i < isVisited.length; i++) {
            if (!isVisited[i] && dungeons[i][0] <= k && k - dungeons[i][1] >= 0) {
                isVisited[i] = true;
                func(k - dungeons[i][1], dungeons, cnt + 1, n);
                isVisited[i] = false;
            }
        }
    }
}