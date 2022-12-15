import java.util.*;

class Solution {
    
    public int solution(int[] queue1, int[] queue2) {
        
        Deque<Integer> deque1 = new ArrayDeque<>();
        Deque<Integer> deque2 = new ArrayDeque<>();
        
        for (int element : queue1) {
            deque1.addLast(element);
        }
        for (int element : queue2) {
            deque2.addLast(element);
        }
        
        long sum1 = deque1.stream().mapToInt(i -> i).sum();
        long sum2 = deque2.stream().mapToInt(i -> i).sum();
                
        for (int cnt = 0; cnt <= queue1.length * 4; cnt++) {
            if (sum1 == sum2) {
                return cnt;
            } else if (sum1 > sum2) {
                deque2.add(deque1.peekFirst());
                sum1 -= deque1.peekFirst();
                sum2 += deque1.pollFirst();
            } else {
                deque1.add(deque2.peekFirst());
                sum2 -= deque2.peekFirst();
                sum1 += deque2.pollFirst();
            }
        }
        
        return -1;
    }
}