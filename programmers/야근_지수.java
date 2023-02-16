import java.util.*;

class Solution {
    
    public long solution(int n, int[] works) {
        
        // pq에 각 일에 대한 작업량 넣기
        Queue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int work : works) {
            pq.add(work);
        }
        
        // 야근 피로도를 최소로 하도록 작업량이 큰 일부터 처리하기
        for (int i = 0; i < n && !pq.isEmpty(); i++) {
            int work = pq.poll() - 1;
            if (work != 0) {
                pq.add(work);
            }
        }
        
        // 야근 피로도를 최소화한 값 구하기
        long result = 0;
        while (!pq.isEmpty()) {
            result += pq.peek() * pq.poll();
        }
        
        return result;
    }
}