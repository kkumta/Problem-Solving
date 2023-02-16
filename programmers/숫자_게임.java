import java.util.*;

class Solution {
    
    public int solution(int[] A, int[] B) {
        int ans = 0;
        Arrays.sort(A);
        Queue<Integer> pq = new PriorityQueue<>();
        for (int num : B) {
            pq.add(num);
        }
        
        // 투포인터 느낌으로
        for (int num : A) {
            while (true) {
                if (pq.isEmpty()) {
                    break;
                }
                if (pq.poll() > num) {
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
}