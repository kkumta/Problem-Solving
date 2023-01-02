import java.util.*;

class Solution {
    
    public int[] solution(String[] operations) {
        Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        Queue<Integer> minHeap = new PriorityQueue<>();
        for (String operation : operations) {
            String[] command = operation.split(" ");
            if (command[0].equals("I")) {
                // 큐에 주어진 숫자 삽입
                int num = Integer.parseInt(command[1]);
                maxHeap.add(num);
                minHeap.add(num);
            } else if (!maxHeap.isEmpty()) {
                if (command[1].equals("1")) {
                    // 가장 큰 숫자 삭제
                    minHeap.remove(maxHeap.poll());
                } else {
                    // 가장 작은 숫자 삭제
                    maxHeap.remove(minHeap.poll());
                }
            }
        }
        
        if (maxHeap.isEmpty()) {
            return new int[]{0, 0};
        }
        
        return new int[]{maxHeap.peek(), minHeap.peek()};
    }
}