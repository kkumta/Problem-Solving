import java.util.*;
import java.io.*;

// 크루스칼 알고리즘 사용
public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static int N, M, edgeCnt, ans;
    static int[] parents;
    static Queue<Info> queue;
    
    public static void main(String[] args) throws IOException {
        
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        parents = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            parents[i] = i;
        }
        queue = new PriorityQueue<>(new Comparator<Info>() {
            @Override
            public int compare(Info o1, Info o2) {
                return o1.cost - o2.cost;
            }
        });
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken());
            int second = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            queue.add(new Info(first, second, cost));
        }
        
        while (edgeCnt != N - 1) {
            Info info = queue.poll();
            if (find(info.first) == find(info.second)) {
                continue;
            }
            union(info.first, info.second);
            ans += info.cost;
            edgeCnt++;
        }
        
        System.out.print(ans);
    }
    
    private static void union(int a, int b) {
        int aRoot = find(a);
        int bRoot = find(b);
        if (aRoot != bRoot) {
            parents[aRoot] = bRoot;
        }
    }
    
    private static int find(int num) {
        if (parents[num] == num) {
            return num;
        } else {
            return parents[num] = find(parents[num]);
        }
    }
    
    private static class Info {
        
        int first, second, cost;
        
        public Info(int first, int second, int cost) {
            this.first = first;
            this.second = second;
            this.cost = cost;
        }
    }
}