class Solution {
    
    public long solution(int k, int d) {
        long ans = 0;
        for (int i = 0; i <= d; i += k) {
            ans += Math.floor(Math.sqrt(d + i) * Math.sqrt(d - i)) / k + 1;
        }
        
        return ans;
    }
}