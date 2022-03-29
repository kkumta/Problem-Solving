import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, leafCount, eraseNode;
    static ArrayList<Integer>[] tree;
    
    public static void main(String[] args) throws IOException {
        
        n = Integer.parseInt(br.readLine());
        tree = new ArrayList[n];
        st = new StringTokenizer(br.readLine());
        
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>(); // 새로운 노드 만들기
        }
        
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(st.nextToken());
            if (num != -1) { // 새로운 노드의 부모 지정하기
                tree[num].add(i);
            }
        }
        
        // 특정 노드 지우기
        eraseNode = Integer.parseInt(br.readLine());
        dfs(eraseNode);
        
        // 리프 노드의 개수 구하기
        for (int i = 0; i < n; i++) {
            if (tree[i].isEmpty()) {
                ++leafCount;
            }
        }
        
        System.out.print(leafCount);
    }
    
    private static void dfs(int eraseNode) {
        
        Stack<Integer> stack = new Stack<>();
        stack.push(eraseNode);
        while (!stack.isEmpty()) {
            int cur = stack.pop();
            if (eraseNode == cur
                && tree[cur].isEmpty()) { // 지워지는 노드가 리프 노드일 경우 그 윗 노드에서 리프 노드를 지운다.
                for (int i = 0; i < n; i++) {
                    if (tree[i].contains(cur)) {
                        tree[i].remove((Object) cur);
                        break;
                    }
                }
            }
            for (int i = 0; i < tree[cur].size(); i++) {
                stack.push(tree[cur].get(i));
            }
            tree[cur].clear();
            tree[cur].add(51);
        }
    }
}
