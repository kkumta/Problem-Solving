import java.util.*;

class Solution {
    
    public int solution(int[] priorities, int location) {
        Queue<Pair> queue = new ArrayDeque<>();
        for (int i = 0; i < priorities.length; i++) {
            queue.add(new Pair(priorities[i], i));
        }
        
        int cnt = 1;
        while (true) {
            Pair cur = queue.peek(); // 현재 가장 앞에 있는 문서를 peek 한다
            
            boolean flag = true; // 현재 가장 앞에 있는 문서가 가장 우선순위가 높은 문서인가?
            for (Pair e : queue) {
                if (e.priority > cur.priority) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) { // 그 문서가 현재 프린터에 있는 문서 중 우선순위가 가장 높으면 그 문서를 인쇄한다
                if (cur.startLoc == location) {// 만약 그 문서가 '내가 인쇄를 요청한 문서'라면 몇 번째로 인쇄되는지를 반환한다
                    return cnt;
                }
                queue.poll();
                cnt++;
            } else { // 그 문서가 현재 프린터에 있는 문서 중 우선순위가 가장 높지 않다면 그 문서를 대기목록의 가장 마지막에 넣는다
                queue.add(queue.poll());
            }
        }
    }
    
    private class Pair {
        
        int priority;
        int startLoc;
        
        public Pair(int priority, int startLoc) {
            this.priority = priority;
            this.startLoc = startLoc;
        }
    }
}