import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    static ArrayList<Integer>[] teams; // 올해 순위 배열
    static boolean[] visited;
    static Stack<Integer> stack = new Stack<>();
    static int n, m;
    static int[] lastRanking;  // 전년도 순위 배열: i번 인덱스에 들어간 팀의 번호는 lastLanking[i]번
    static int[] order; // 전년도 팀의 순위: i번 팀의 순위는 order[i]
    static boolean isPossible;
    
    public static void main(String[] args) throws IOException {
        
        // 입력
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            n = Integer.parseInt(br.readLine());
            teams = new ArrayList[n + 1];
            for (int j = 1; j <= n; j++) {
                teams[j] = new ArrayList<>();
            }
            
            lastRanking = new int[n + 1];
            order = new int[n + 1];
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                lastRanking[j] = Integer.parseInt(st.nextToken());
                order[lastRanking[j]] = j;
            }
            
            for (int j = 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    teams[lastRanking[j]].add(lastRanking[k]);
                }
            }
            
            m = Integer.parseInt(br.readLine());
            for (int j = 0; j < m; j++) {
                st = new StringTokenizer(br.readLine());
                int firstTeam = Integer.parseInt(st.nextToken());
                int secondTeam = Integer.parseInt(st.nextToken());
                if (order[firstTeam] > order[secondTeam]) {
                    teams[secondTeam].remove(teams[secondTeam].indexOf(firstTeam));
                    teams[firstTeam].add(secondTeam);
                } else {
                    teams[firstTeam].remove(teams[firstTeam].indexOf(secondTeam));
                    teams[secondTeam].add(firstTeam);
                }
            }
            
            visited = new boolean[n + 1];
            
            isPossible = true;
            for (int j = 1; j <= n; j++) {
                for (int k = 0; k < teams[j].size(); k++) {
                    if (teams[j].size() == teams[teams[j].get(k)].size()) {
                        isPossible = false;
                        break;
                    }
                }
            }
            
            if (isPossible) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j]) {
                        dfs(j);
                    }
                }
                while (!stack.isEmpty()) {
                    sb.append(stack.pop() + " ");
                }
            } else {
                sb.append("IMPOSSIBLE");
            }
            sb.append("\n");
        }
        System.out.print(sb.toString());
    }
    
    private static void dfs(int v) {
        
        visited[v] = true;
        
        for (int i : teams[v]) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        
        stack.push(v);
    }
}