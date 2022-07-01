import java.io.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        String[] memo = new String[n + 1];
        
        memo[1] = "CY";
        if (n >= 2) {
            memo[2] = "SK";
        }
        if (n >= 3) {
            memo[3] = "CY";
        }
        if (n >= 4) {
            memo[4] = "SK";
        }
        
        // memo[n - 상근이가 처음 가져가는 돌의 개수] 3개 중 하나라도 창영이일 경우 상근이 우승
        // 상근이가 처음 돌을 가져가는 사람이기 때문에 1, 3, 4 어떤 개수의 돌을 가져가더라도 우승하지 못할 경우를 제외하고는 모두 상근이가 우승한다.
        for (int i = 5; i <= n; i++) {
            if (memo[i - 1] == "CY" || memo[i - 3] == "CY" || memo[i - 4] == "CY") {
                memo[i] = "SK";
            } else {
                memo[i] = "CY";
            }
        }
        
        System.out.print(memo[n]);
    }
}
