import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    static ArrayList<Integer>[] students;
    static boolean[] visited;
    static Stack<Integer> stack = new Stack<>();
    static int n, m;
    
    public static void main(String[] args) throws IOException {
        
        // 입력
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        visited = new boolean[n + 1];
        
        students = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            students[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken());
            int second = Integer.parseInt(st.nextToken());
            students[first].add(second);
        }
        
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        
        while (!stack.isEmpty()) {
            sb.append(stack.pop() + " ");
        }
        
        System.out.print(sb.toString());
    }
    
    private static void dfs(int v) {
        
        visited[v] = true;
        
        for (int i : students[v]) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        
        stack.push(v);
    }
}