import java.util.*;

class Solution {

    int count;
    boolean[] isVisited;
    int[][] info;

    public int solution(int n, int[][] computers) {

        int answer = 0;
        isVisited = new boolean[n];
        info = computers;

        for (int i = 0; i < n; i++) {
            if (!isVisited[i]) {
                dfs(i);
            }
        }

        answer = count;
        return answer;
    }

    private void dfs(int start) {

        Stack<Integer> stack = new Stack<Integer>();
        stack.push(start);
        while (!stack.isEmpty()) {
            int x = stack.pop();
            if (!isVisited[x]) {
                isVisited[x] = true;
                for (int i = 0; i < info.length; i++) {
                    if ((!isVisited[i]) && (info[x][i] == 1 || info[i][x] == 1)) {
                        stack.push(i);
                    }
                }
            }
        }
        ++count;
    }
}
