import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    public static void main(String[] args) throws IOException {
        
        int t = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < t; i++) {
            int k = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            
            // 우선순위 큐(최소 힙)를 선언한다
            PriorityQueue<Long> pq = new PriorityQueue<>(k);
            
            // 우선순위 큐에 파일의 크기를 추가한다
            for (int j = 0; j < k; j++) {
                pq.add(Long.parseLong(st.nextToken()));
            }
            
            Long cost = 0L; // 총 비용
            
            // 우선순위 큐의 크기가 1이 될 때까지 파일을 합치는 행위를 계속한다
            while (pq.size() != 1) {
                Long sum = pq.remove() + pq.remove(); // 가장 작은 수 2개를 지우고 둘을 더해준다
                pq.add(sum); // 더한 수를 다시 우선순위 큐에 넣고
                cost += sum; // 더한 수 == 해당 파일 2개를 합칠 때 든 비용이기에 총 비용에 더해준다
            }
            
            sb.append(cost + "\n");
        }
        
        System.out.print(sb.toString());
    }
}
