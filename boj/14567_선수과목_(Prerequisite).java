import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    static ArrayList<Integer>[] subjects;
    static int[] dp;
    static int n, m;
    
    public static void main(String[] args) throws IOException {
        
        // 입력
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        dp = new int[n + 1];
        
        subjects = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            subjects[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken());
            int second = Integer.parseInt(st.nextToken());
            subjects[second].add(first);
        }
        
        // 해당 과목을 듣기 위한 최소 학기 수 구하기
        dp[1] = 1;
        sb.append(1 + " ");
        for (int i = 2; i <= n; i++) {
            if (subjects[i].isEmpty()) {
                dp[i] = 1;
            } else {
                int max = 0;
                for (Integer number : subjects[i]) {
                    if (dp[number] > max) {
                        max = dp[number];
                    }
                }
                dp[i] = max + 1;
            }
            sb.append(dp[i] + " ");
        }
        
        System.out.print(sb.toString());
    }
}