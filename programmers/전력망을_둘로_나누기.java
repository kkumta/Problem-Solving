import java.util.*;

class Solution {
    
    public int solution(int n, int[][] wires) {
        int result = n;
        boolean[] visited = new boolean[n + 1];
        List<Integer>[] wireList = new ArrayList[n + 1];
        
        for (int i = 1; i <= n; i++) {
            wireList[i] = new ArrayList<>();
        }
        
        for (int[] wire : wires) {
            wireList[wire[0]].add(wire[1]);
            wireList[wire[1]].add(wire[0]);
        }
        
        for (int[] wire : wires) {
            wireList[wire[0]].remove(Integer.valueOf(wire[1]));
            wireList[wire[1]].remove(Integer.valueOf(wire[0]));
            int cnt = dfs(wire[0], wireList, visited);
            if (Math.abs(n - cnt * 2) < result) {
                result = Math.abs(n - cnt * 2);
            }
            wireList[wire[0]].add(wire[1]);
            wireList[wire[1]].add(wire[0]);
        }
        
        return result;
    }
    
    private int dfs(int start, List<Integer>[] wireList, boolean[] visited) {
        int cnt = 0; // 끊어진 트리에 있는 송전탑의 개수
        Arrays.fill(visited, false);
        Stack<Integer> stack = new Stack<>();
        stack.add(start);
        while (!stack.isEmpty()) {
            int cur = stack.pop();
            visited[cur] = true;
            cnt++;
            for (int i = 0; i < wireList[cur].size(); i++) {
                int num = wireList[cur].get(i);
                if (!visited[num]) {
                    stack.push(num);
                }
            }
        }
        
        return cnt;
    }
}