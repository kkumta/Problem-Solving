import java.io.*;
import java.util.*;

public class Main {
    
    private static class Pair implements Comparable<Pair> {
        
        int s;
        int t;
        
        public Pair(int s, int end) {
            this.s = s;
            this.t = end;
        }
        
        @Override
        public int compareTo(Pair o) {
            if (this.s == o.s) {
                return this.t - o.t;
            }
            return this.s - o.s;
        }
    }
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws IOException {
        
        int n = Integer.parseInt(br.readLine());
        Pair[] schedule = new Pair[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            schedule[i] =
                new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        
        // 스케줄 정렬
        Arrays.sort(schedule);
        
        // 스케줄 배정
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
        priorityQueue.add(schedule[0].t);
        
        for (int i = 1; i < schedule.length; i++) {
            if (priorityQueue.peek() <= schedule[i].s) {
                priorityQueue.poll();
            }
            priorityQueue.add(schedule[i].t);
        }
        
        System.out.println(priorityQueue.size());
    }
}
