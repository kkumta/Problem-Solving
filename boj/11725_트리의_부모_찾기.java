import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int[] parents;
    static LinkedList<Integer>[] tree;
    
    public static void main(String[] args) throws IOException {
        
        // 입력
        int n = Integer.parseInt(br.readLine());
        parents = new int[n + 1];
        tree = new LinkedList[n + 1];
        for (int i = 1; i <= n; i++) {
            tree[i] = new LinkedList<Integer>();
        }
        
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken());
            int second = Integer.parseInt(st.nextToken());
            tree[first].add(second);
            tree[second].add(first);
        }
        
        bfs(1);
        
        for (int i = 2; i <= n; i++) {
            sb.append(parents[i] + "\n");
        }
        
        System.out.print(sb.toString());
    }
    
    private static void bfs(int root) {
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int i = 0; i < tree[cur].size(); i++) {
                if (parents[tree[cur].get(i)] == 0) {
                    parents[tree[cur].get(i)] = cur;
                    queue.add(tree[cur].get(i));
                }
            }
        }
    }
}