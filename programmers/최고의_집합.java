import java.util.*;

class Solution {
    public int[] solution(int n, int s) {
        if (n > s) {
            return new int[]{-1};
        }
        
        int[] ans = new int[n];
        int quotient = s / n;
        int remainder = s % n;
        
        Arrays.fill(ans, quotient);
        for (int idx = ans.length - 1; remainder > 0; idx--, remainder--) {
            ans[idx]++;
        }
        
        return ans;
    }
}