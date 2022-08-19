import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static ArrayList<Integer>[] g;
    static int n, m;
    static boolean[] visited;
    static boolean isTrue;
    
    public static void main(String[] args) throws IOException {
        
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        g = new ArrayList[n];
        visited = new boolean[n];
        
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken());
            int second = Integer.parseInt(st.nextToken());
            g[first].add(second);
            g[second].add(first);
        }
        
        for (int i = 0; i < n; i++) {
            dfs(i, 0);
            if (isTrue) {
                System.out.print(1);
                return;
            }
        }
        
        System.out.print(0);
    }
    
    private static void dfs(int v, int cnt) {
        
        if (cnt >= 4) {
            isTrue = true;
            return;
        }
        
        visited[v] = true;
        
        for (int i = 0; i < g[v].size(); i++) {
            if (!visited[g[v].get(i)]) {
                dfs(g[v].get(i), cnt + 1);
            }
        }
        
        visited[v] = false;
    }
}