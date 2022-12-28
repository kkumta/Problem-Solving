import java.util.*;

class Solution {
    
    public int solution(int[] scoville, int K) {
        Queue<Long> foods = new PriorityQueue<>();
        for (int food : scoville) {
            foods.add((long) food);
        }
        
        int ans = 0;
        while (foods.peek() < K) { // 스코빌 지수가 K보다 낮은 음식이 존재할 경우
            
            if (foods.size() == 1) { // 스코빌 지수가 K보다 낮은 음식 1개만 존재할 경우
                return -1;
            }
            
            // 음식을 섞는다
            ans++;
            long first = foods.poll();
            long second = foods.poll();
            foods.add(first + second * 2);
        }
        
        return ans;
    }
}