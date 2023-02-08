import java.util.*;
import java.io.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    static int N;
    static List<Integer>[] indegree; // 선행자 모음
    static List<Integer>[] outdegree; // 후행자 모음
    static int[] time, ans;
    
    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        indegree = new ArrayList[N + 1];
        outdegree = new ArrayList[N + 1];
        time = new int[N + 1];
        ans = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            indegree[i] = new ArrayList<>();
            outdegree[i] = new ArrayList<>();
        }
        
        // 각 건물을 짓는 데 걸리는 시간, 그 건물의 선행자 입력
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            time[i] = Integer.parseInt(st.nextToken());
            ans[i] = time[i];
            while (true) {
                int input = Integer.parseInt(st.nextToken());
                if (input == -1) {
                    break;
                }
                indegree[i].add(input);
                outdegree[input].add(i);
            }
        }
        
        Queue<Integer> queue = new ArrayDeque<>();
        for (int i = 1; i <= N; i++) {
            if (indegree[i].isEmpty()) { // 선행자가 없다면 큐에 넣는다
                queue.add(i);
            }
        }
        
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int next : outdegree[cur]) {
                ans[next] = Math.max(ans[next], ans[cur] + time[next]);
                indegree[next].remove(Integer.valueOf(cur));
                if (indegree[next].isEmpty()) {
                    queue.add(next);
                }
            }
        }
        
        for (int i = 1; i <= N; i++) {
            sb.append(ans[i]).append("\n");
        }
        System.out.print(sb.toString());
    }
}
